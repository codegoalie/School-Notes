ALPHA = "abcdefghijklmnopqrstuvwxyz"

def cypher x
    ((15 * x) + 7) % 34
end

(0..34).each do |x|
  puts "#{ALPHA[x,1]}(#{x}): #{cypher x}"
end

