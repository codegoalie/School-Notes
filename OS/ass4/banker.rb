RESOURCE_COUNT = 5
INITIAL_PROCESSES = 4
MAX_RESOURCES = 10

available_resources = Array.new(RESOURCE_COUNT)
allocated = Array.new
max = Array.new
INITIAL_PROCESSES.times do
  process_allocated = Array.new
  process_max = Array.new
  RESOURCE_COUNT.times do
    process_allocated << rand(MAX_RESOURCES)
    process_max << rand(MAX_RESOURCES)
  end
  allocated << process_allocated
  max << process_max
end

state = Array.new()
RESOURCE_COUNT.times do 
  state << rand(MAX_RESOURCES)
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

def banker(available_resources, allocated, max)
  if(allocated.size == 0)
    return true
  else
    checking_process = 0
    while(checking_process < INITIAL_PROCESSES.size && safe_state = false) do
      if(resources_available(available_resources, allocated[checking_process], max[checking_process]))
        #release_resources
        # this shoudl recurse at some point
      end
    end
  end
end

def resources_available(available_resources, allocated, max)
  RESOURCE_COUNT.times do |i|
    if(max[0]-allocated[0] > available_resources)
      return false
    end
  end
  return true
end


