require 'mysql-cellophane.rb'

describe MySQLc do
  it "should assign the correct instance values by default" do 
    db = MySQLc.new
    db.id_field.should be(1)
    db.id.should be(1)
    db.field_list.should eql("*")
  end

  describe "Library" do
    before do
      @db = MySQLc.new({:socket => '/var/run/mysqld/mysqld.sock', 
                        :user => 'cello_tester', 
                        :password => '', 
                        :database => 'cello_test'})
    end

    it "should escape single quotes" do
      @db.esc("one'two").should eql("one\\'two")
    end

    it "should turn array into escaped quoted string" do
      @db.quoted_string_from([1,"one'two",3]).should eql("'1','one\\'two','3'")
    end

    describe "Extraction Methods" do
      before(:all) do
        @value_array = [1,2,3]
        @field_array = [:one, :two, :three]
        @value_array.size.times do |i|
          @generic_hash ||= {}
          @generic_hash[@field_array[i]] = @value_array[i] 
        end
      end

      it "should extract_values_from a hash" do
        @db.extract_values_from(@generic_hash).should be @value_array
      end

      it "should extract_fields_from a hash" do
        @db.extract_fields_from(@generic_hash).should be @field_array
      end
    end
  end

  describe "SELECT" do
    before do
      @db = MySQLc.new({:socket => '/var/run/mysqld/mysqld.sock', 
                        :user => 'cello_tester', 
                        :password => '', 
                        :database => 'cello_test'})
      @db.table = "test_one"
    end

    it "should get all fields and rows by default" do
      result = @db.select
      result.num_rows.should be 2
      result.num_fields.should be 3
    end

    it "should get only the specified fields" do
      @db.field_list = 'name'
      result = @db.select
      result.num_fields.should be 1
    end

    it "should append extra_cond correctly" do
      @db.extra_cond = "name = '#{@db.esc('Chris')}'"
      result = @db.select
      result.num_rows.should be 1
    end

    it "should allow in-line attribute specification" do
      result = @db.select "test_one", "name, age", "id", "1", "age = '#{@db.esc(26)}'"
      result.num_fields.should be 2
      result.num_rows.should be 1
    end
  end

  describe "INSERT" do
    before do
      @db = MySQLc.new({:socket => '/var/run/mysqld/mysqld.sock', 
                        :user => 'cello_tester', 
                        :password => '', 
                        :database => 'cello_test'})
      @db.table = "test_one"
      result = @db.select
      @orig_rows = result.num_rows
      @insert_hash = { :name => 'Bobby', :age => '25' }
      @new_id = @db.insert()
      @result = @db.select
    end

    it "should insert a new record" do
      @result.num_rows.should be orig_rows+1
    end

    it "should insert the correct values and return the newly inserted id" do
      @db.field_list  = 'name, age'
      @db.id_field    = 'id'
      @db.id          = new_id
      result = @db.select
      result.num_rows.should be 1
      result.fetch_array.should be @insert_hash
    end
  end

  describe "UPDATE" do
    it "should not insert a new row" do
    end

    it "should change the value of an attribute" do 
    end

    it "should only effect teh appropriate rows" do
    end
  end
end
