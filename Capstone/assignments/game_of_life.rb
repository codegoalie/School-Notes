
class Field 
  def initialize(field_size, randomize=true)
    @field_size = field_size
    @data = Array.new
      (0..@field_size-1).each do |row|
        @data[row] = Array.new
        (0..@field_size-1).each do |col|
          @data[row][col] = randomize ? rand(2) : 0
        end
      end
    unless randomize
      @data[0][2] = 1
      @data[1][3] = 1
      @data[2][1] = 1
      @data[2][2] = 1
      @data[2][3] = 1
    end
  end

  def print_data
    (0..@field_size-1).each do |row|
      (0..@field_size-1).each do |col|
        if @data[row][col] == 0
          print ". "
        else
          print "* "
        end
        #print "#{@data[row][col]} "
      end
      print "\n"
    end
  end

  def iterate

    new_data = Marshal::load(Marshal.dump(@data))
    (0..@field_size-1).each do |row|
      (0..@field_size-1).each do |col|
        neighbors = 0
        # check above 
        if row > 0
          #puts "checking row above"
          neighbors += @data[row-1][col-1] if col > 0
          neighbors += @data[row-1][col]
          neighbors += @data[row-1][col+1] if col < @field_size-1
        end

        if col > 0
          neighbors += @data[row][col-1]
          neighbors += @data[row][col+1] if col < @field_size-1
        end

        if row < @field_size-1
          neighbors += @data[row+1][col-1] if col > 0
          neighbors += @data[row+1][col]
          neighbors += @data[row+1][col+1] if col < @field_size-1
        end

        #print "Cell[#{row}][#{col}] has #{neighbors} neighbors "

        if @data[row][col] == 1 && (neighbors < 2 || neighbors > 3)
          new_data[row][col] = 0
          #print "and dies"
        elsif @data[row][col] == 0 && neighbors == 3
          new_data[row][col] = 1
          #print "and lives"
        else
          #print "and keeps on being #{@data[row][col]}: #{new_data[row][col]}"
        end
        #print "\n"
      end
    end
    @data = new_data
  end
end


####################################################################

puts "\nWelcome to the Game of Life!\n\n"
puts "Pass a second parameter to start with random data" if ARGV[1].nil?
if ARGV.size > 0
  field_size = ARGV[0].to_i
  puts "Playing on a #{field_size} x #{field_size} field"
else
  field_size = 5
  puts "Defaulting to a #{field_size} x #{field_size} field. Run with an integer param to " +
    "set a custom size."
end

field = Field.new(field_size, ARGV[1])
puts "Initial State:"
field.print_data
puts "Starting in 3 seconds..."
sleep 3

ctrl_char = ''
generation = 1
#until ctrl_char =~ /q/i
until generation == 50
  field.iterate
  puts "Generation #{generation}:"
  field.print_data
  #puts "Press enter to continue; q to quit."
  #ctrl_char = gets.chomp
  generation += 1
  sleep 1
end
