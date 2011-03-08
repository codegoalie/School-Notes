def EGCD(b,m,recLevel=0)
  if b % m == 0
    tmpVal = [0,1]
    return tmpVal
  else
    tmpVal = EGCD(m, b % m, recLevel+1)
    tmpVal2 = [tmpVal[1], tmpVal[0]-tmpVal[1] * ((b/m).to_i)]
    if recLevel == 0
      return tmpVal2[0] % m
    else
      return tmpVal2
    end
  end
end

# param: integer a    a is >= b
# # param: integer b    b is <= a
# # return: integer    the greatest common divisor of a and b
def gcd(a, b)
  # Make sure that a >= b, or exit
  if a < b
    print "Error: a must not be less than b - ",
      "here a=", a, " and b=", b, "\n"
    exit
  end

  # Cast parameters a and b to integers x and y
  x = a.to_i
  y = b.to_i

  # With each iteration, x is replaced by y, 
  # and y is replaced by x mod y, which
  # is the remainder when x is divided by y. 
  # When y is zero, the value of x at that point,
  # the last non-zero remainder in the procedure, 
  # is the greatest common divisor of a and b
  while y != 0
    r = x % y
    x = y
    y = r
  end

  # Return the last non-zero remainder from the while loop
  return x
end

def is_prime n
  for d in 2..(n - 1)
    if (n % d) == 0
      return false
    end
  end

  true
end
