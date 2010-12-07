class MySQLc
  #require 'rubygems'
  require 'mysql'
  
  attr_accessor :table, :field_list, :id_field, :id, :extra_cond,
    :result, :query

  # public method initialize (constructor)
  #
  # initializes common instance vars
  def initialize(options = {})
    log = File.new('sql_log.log', 'a')
    log.puts "Created New MySQLc instance"
    log.close

    options[:host]      ||= 'localhost'
    options[:user]      ||= 'root'
    options[:password]  ||= 'secure'
    options[:database]  ||= 'test'
    options[:port]      ||= nil
    options[:socket]    ||= nil
    options[:flag]      ||= nil

    @options = {}
    @options.merge!(options)

    @field_list = "*"
    @id_field   = 1
    @id         = 1
    @cache      = {}
  end

  # private method connect
  #
  # takes hash of connection ooptions, has default also
  # sets @db as Mysql instance
  def connect(options = {})
    @options.merge(options)

    @db = Mysql.connect(@options[:host], @options[:user], @options[:password], @options[:database],
                         @options[:port], @options[:socket], @options[:flag])
  end

  # private method execute
  #
  # builds query from parts if neccessary
  # returns cached result if exists
  # saves result in @result
  def execute
    log = File.new('sql_log.log', 'a')
    log.puts "Before: #{@query}"
    log.close
    build_query if(@query.nil?) 

    query = @query # keep local copy of query string
    @query = nil #prevent same queries from running more than once without rebuilding

    #print "#{query}\n"
    #if(@cache[query].nil? && use_cache)
      connect if @db.nil? #connect to the database if needs be

      log = File.new('sql_log.log', 'a')
      log.puts "To Execute: #{query}"
      log.close
      @result = @db.query(query) # run query
      log = File.new('sql_log.log', 'a')
      log.puts "After: #{@query}"
      log.close
      @cache[query] = @result # save result to cache hash

    #else
      #@result = @cache[query]
    #end
  end

  # private method build_query
  #
  # constructs SELECT query from instance vars
  def build_query
    @query = "SELECT #{esc(@field_list)} " + "FROM #{esc(@table)} WHERE " +
      "#{esc(@id_field)} = #{esc(@id)}"
    @query << " AND #{@extra_cond}" unless @extra_cond.nil?
  end


  # private method set_attributes
  #
  # sets instance attributes from fucntion parameters
  # called by each public API methods
  def set_attributes(*vals)
    # when vals gets strung along from another *vals, the original 
    # empty array becomes the first element of the new vals
    # so, we need to pull the first element off and work on that
    vals = vals[0] if vals[0].class.to_s == 'Array'

    if vals.size >= 1 && vals[0] != "" 
      @table      = vals[0] if vals.size >= 1
      @field_list = vals[1] unless vals.size < 2
      @id_field   = vals[2] unless vals.size < 3
      @id         = vals[3] unless vals.size < 4
      @extra_cond = vals[4] unless vals.size < 5
    end
  end

  # public method select
  #
  # simply runs the query and returns the result
  def select(*vals)
    #print "#{vals}\n"
    set_attributes vals 
    execute
  end

  # public method insert
  #
  # inserts a new row into the table 
  # with the given values
  def insert(inserts, *vals)
    set_attributes vals

    fields = extract_fields_from inserts 
    values = extract_values_from inserts 


    @query = "INSERT INTO #{esc(@table)} (#{fields}) VALUES " +
      "(#{values})"
    execute
    inserted_id
  end

  # public method inserted_id
  #
  # gets the last inserted ID and returns it
  def inserted_id
    @query = "SELECT LAST_INSERT_ID();"
    execute
    @result.fetch_row[0]
  end

  # public method update
  #
  # takes a given hash and updates the correct row
  def update(updates, *vals)
    set_attributes vals
    
    sets = updates.map {|key,val| "#{key} = '#{esc(val)}'"}

    @query = ""
    if @id_field != ""
      @query += "WHERE #{@id_field} = #{@id}"
    end

    if @extra_cond != "" && !@extra_cond.nil?
      @query += ((@query == "") ? " WHERE " : " AND ") + @extra_cond
    end

    @query = "UPDATE #{@table} SET #{sets.join ','} " + @query
    execute
  end

  # public method quoted_string_from
  #
  # library function to convert values
  # in a hash (or plain array) into an
  # escaped single quoted comma
  # delimited string
  def quoted_string_from hash_or_array
    array =  hash_or_array.class == Hash ? hash_or_array.values : hash_or_array
    array.collect { |raw| "'#{esc(raw)}'"}.join(',')
  end

  # public method extract_values_from 
  #
  # takes a hash and returns a songle 
  # quoted string of the values
  def extract_values_from hash
    quoted_string_from hash
  end

  # extract_fields_from
  #
  # takes a hash and returns a
  # comma separated list of keys
  def extract_fields_from hash
    hash.keys.join(',')
  end


  # public method esc
  #
  # takes string parameter
  # returns saftely escaped string
  def esc(raw_string)
    connect if @db.nil? #connect to the database if needs be

    @db.quote(raw_string.to_s)
  end


  #private :connect, :set_attributes
end

