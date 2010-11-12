
class MySQLc
  require 'rubygems'
  require 'mysql'
  
  attr_accessor :table, :field_list, :id_field, :id, :extra_cond,
    :result, :query

  # public method initialize (constructor)
  #
  # initializes common instance vars
  def initialize
    @field_list = '*'
    @id_field   = 1
    @id         = 1
    @cache      = {}
  end

  # private method connect
  #
  # takes hash of connection ooptions, has default also
  # sets @db as Mysql instance
  def connect(options = {})
    options[:host]      ||= 'localhost'
    options[:user]      ||= 'root'
    options[:password]  ||= 'secure'
    options[:database]  ||= 'test'
    options[:port]      ||= nil
    options[:socket]    ||= nil
    options[:flag]      ||= nil

    @db = Mysql.connect(options[:host], options[:user], options[:password], options[:database],
                         options[:port], options[:socket], options[:flag])
  end

  # private method execute
  #
  # builds query from parts if neccessary
  # returns cached result if exists
  # saves result in @result
  def execute
    build_query if(@query.nil?) 

    query = @query # keep local copy of query string
    @query = nil #prevent queries from running more than once

    if(@cache[query].nil?)
      connect if @db.nil? #connect to the database if needs be

      @result = @db.query(query) # run query
      @cache[query] = @result # save result to cache hash
    else
      @result = @cache[query]
    end
  end

  # private method build_query
  #
  # constructs SELECT query from instance vars
  def build_query
    @query = "SELECT #{esc(@field_list)} FROM #{esc(@table)} WHERE " +
      "#{esc(@id_field)} = #{esc(@id)}"
    @query << "AND #{@extra_cond}" unless @extra_cond.nil?
  end

  # public method esc
  #
  # takes string parameter
  # returns saftely escaped string
  def esc(raw_string)
    connect if @db.nil?
    @db.quote(raw_string.to_s)
  end


  #private :connect
end

