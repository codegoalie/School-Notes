class Crypto

  def self.gcd(a,b)
    a = a.abs
    b = b.abs
    while b != 0
      k = a % b
      a = b
      b = k
    end
    a
  end

  def self.egcd(a_sub_zero,b_sub_zero)
    a = a_sub_zero
    s_sub_a = 1
    t_sub_a = 0

    b = b_sub_zero
    s_sub_b = 0
    t_sub_b = 1

    if a < 0
      a = a.abs
      s_sub_a = -1
    end
    if b < 0
      b = b.abs
      t_sub_b = -1
    end
  end

  def self.miller_rabin(n,s)
    b=bitarray(n-1)
    i=b.size 
    j =1
    while j <= s
      a = 1 + (rand(n-2).to_i)
      if witness(a,n,i,b) == true
        return false
      end
      j+=1
    end
    return true
  end
  def self.witness(a,n,i,b)
    d=1
    x=0
    while i > 0 
      x = d 
      d = (d**2) % n
      if ( (d == 1) && (x != 1) && (x != (n-1)) )
        return true
        enddnd
        if ( b[i-1] == 1 )
          d = (d * a ) % n
        end
        i -= 1
      end
      if ( d != 1) 
        return true
      end
      return false
    end
  end
end

