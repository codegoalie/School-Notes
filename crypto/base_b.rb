def base_b_rep n, b
  if n != 0
    q = (n / b).floor
    r = n % b
    "#{base_b_rep q, b}#{r}"
  end
end

def bignum_add val_array1, val_array2, base
  result = Array.new
  i = 0
  carry = 0
  while i < val_array1.size
    k = (val_array1[i] + val_array2[i]) + carry
    if k >= base
      k -= base
      carry = 1
    else
      carry = 0
    end
    result[i] = k
    i += 1
  end
  if carry == 1
    "overflow"
  else
    result
  end
end

