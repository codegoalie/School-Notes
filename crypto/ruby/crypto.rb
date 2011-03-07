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

    while b != 0
      q = 


end
