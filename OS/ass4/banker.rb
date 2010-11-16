# banker.rb

RESOURCE_COUNT = 5
INITIAL_PROCESSES = 4
MAX_RESOURCES = 5

def banker(available_resources, allocated, max)
  if(allocated.size == 0)
    return true
  else
    orig_size = allocated.size
    #print "#{orig_size} processes to check\n"
    checking_process = 0
    while(checking_process < allocated.size)
      if(resources_available(available_resources, allocated[checking_process], max[checking_process]))
        #release_resources
        RESOURCE_COUNT.times do |i|
          available_resources[i] += allocated[checking_process][i]
        end
        allocated.delete_at checking_process
        max.delete_at checking_process
        #print "process #{checking_process} finishes\n"
      else
        checking_process += 1
      end
    end
    if(orig_size == allocated.size)
      return false
    else
      return banker(available_resources, allocated, max)
    end
  end
end

def resources_available(available_resources, allocated, max)
  RESOURCE_COUNT.times do |i|
    #print "max #{max[i]}\n"
    #print "alloc #{allocated[i]}\n"
    #print "avail #{available_resources[i]}\n"
    if(max[i]-allocated[i] > available_resources[i])
      return false
    end
  end
  return true
end




allocated = Array.new
max = Array.new
INITIAL_PROCESSES.times do
  process_allocated = Array.new
  process_max = Array.new
  RESOURCE_COUNT.times do
    allocate = rand(MAX_RESOURCES)
    process_allocated << allocate
    begin
      temp_max = rand(MAX_RESOURCES)
    end while temp_max < allocate
    process_max << temp_max
  end
  allocated << process_allocated
  max << process_max
end

state = Array.new #(RESOURCE_COUNT, 0)
RESOURCE_COUNT.times do 
  state << rand(MAX_RESOURCES/2)
end

print "Current State of Available Resources:\n"
print state.to_s
print "\n\nProcesses' Current Resources:\n"
INITIAL_PROCESSES.times do |i|
  print "P#{i} #{allocated[i].to_s}\n"
end
print "\nProcesses' Max Resources:\n"
INITIAL_PROCESSES.times do |i|
  print "P#{i} #{max[i].to_s}\n"
end

print "\nThis is a "
print banker(state, allocated, max) ? "SAFE" : "UNSAFE"
print " state\n"
