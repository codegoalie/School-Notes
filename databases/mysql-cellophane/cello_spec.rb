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
    end

    it "should insert a new record" do
      result = @db.select
      orig_rows = result.num_rows
      new_id = @db.insert({ :name => 'Bobby', :age => '25' })
      result = @db.select
      result.num_rows.should be orig_rows+1
    end

  end
end
