require 'ncurses'

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

  def print_data(start_row, start_col)
    current_row = start_row
    current_col = start_col
    (0..@field_size-1).each do |row|
      (0..@field_size-1).each do |col|
        char = if @data[row][col] == 0
          ". "
        else
          "* "
        end
        Ncurses.mvaddstr(current_row, current_col*2,char)
        current_col+=1
        #print "#{@data[row][col]} "
      end
      current_row += 1
      current_col = start_col
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

Ncurses.initscr
Ncurses.clear
Ncurses.mvaddstr(0,0, "Welcome to the Game of Life!")
Ncurses.mvaddstr(1,0, "Pass a second parameter to start with random data") if ARGV[1].nil?
if ARGV.size > 0
  field_size = ARGV[0].to_i
  Ncurses.mvaddstr(2,0, "Playing on a #{field_size} x #{field_size} field")
else
  field_size = 5
  Ncurses.mvaddstr(2,0, "Defaulting to a #{field_size} x #{field_size} field. Run with an integer param to " +
    "set a custom size.")
end

field = Field.new(field_size, ARGV[1])
Ncurses.mvaddstr(3,0, "Initial State:")
Ncurses.mvaddstr(4,0, "Starting in 3 seconds...")
field.print_data(5,0)
Ncurses.refresh
sleep 3

generation = 1

until generation == 50
  field.iterate
  Ncurses.clear
  Ncurses.mvaddstr(0,0,  "Generation #{generation}:")
  field.print_data(1,0)
  Ncurses.refresh
  generation += 1
  sleep 1
end
Ncurses.endwin
