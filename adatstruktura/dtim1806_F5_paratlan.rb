#Demeter Tamas
#dtim1806
#511/2
#F5 paratlan

#cserek szama - globalis
$cserek=0

class Heap
  #Heap adattagok - meret,elemek
  @meret=0
  @elemek=[]

  #konstruktor - inicializalja a meretet es elvegzi a kupacolast
  def initialize(n, v)
    @meret=n
    @elemek=v
    k=(n-1)/2 #-1
    k.downto(0) do |i|
      kupacol(i)
    end
  end

  #jobbgyerek
  def jobbgyerek(i)
    2*i+2
  end

  #balgyerek
  def balgyerek(i)
    2*i+1
  end

  #adott indexen levo elem visszaadasa
  def elem(i)
    @elemek[i]
  end

  #3 elem maximuma
  def max(a,b,c)
    if @elemek[a]>@elemek[b]
      if @elemek[a]>@elemek[c]
        a
      else
        c
      end
    else
      if @elemek[b]>@elemek[c]
        b
      else
        c
      end
    end
  end

  #csere
  def csere(a, b)
    $cserek+=1
    @elemek[a],@elemek[b]=@elemek[b],@elemek[a]
  end

  #standard kupacol algoritmus
  def kupacol(i)
    if i<(@meret-1)/2
      x=balgyerek(i)
      y=jobbgyerek(i)
      m=max(i,x,y)
      if m!=i
        csere(i,m)
        kupacol(m)
      end
    end
  end

  #maximum torlese
  def torolmax
    @elemek[0]=@elemek[@meret-1]
    @meret-=1
    kupacol(0)
  end

  #elemek kiirasa
  def kiir
    print @elemek
  end

end

#kupacrendezes
def kupacrendezes(n,v)
  temp=Heap.new(n,v)
  n.downto(0) do |i|
    v[i]=temp.elem(0)
    temp.torolmax
  end

end

#vektor beolvasasa
f = File.open("heap.txt","r")
lines = f.readlines
m=lines[0].to_i
lines.shift

#atalakitas integerre
lines.each_index do |i|
  lines[i]=lines[i].to_i
end

kupacrendezes(m,lines)

#eredmeny kiirasa
puts $cserek
g= File.new("output.txt","w")
g.puts "#{$cserek} csere"
g.close
f.close