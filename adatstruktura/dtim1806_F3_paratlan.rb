#Demeter Tamas
#dtim1806
#511/2
#F3

#verem
class Verem
  #egy adat tulajdonsagai: ertek, rakovetkezo adat 
  class Adat
    attr_accessor :ertek, :next
    def initialize(x)
      @ertek=x
      @next=nil
    end
  end

  #verem inicializalasa
  def initialize
    @adatok=[]
  end

  #uj elem betevese
  def push(x)
    adat=Adat.new(x)
    if @adatok[-1] != nil
    @adatok[-1].next=adat.object_id
    end
    @adatok.push(adat)
  end

  #elem pop
  def pop
    x=@adatok[-1]
    if  @adatok[-2] != nil
    @adatok[-2].next=@adatok[-1].next
    end
    @adatok.delete_at(-1)
    x.ertek
  end

  #verem kiirasa
  def kiir
    @adatok.each do |x|
      print "#{x.ertek} "
    end
  end

  #verem uritese
  def urit
    @adatok=[]
  end

end

v=Verem.new
f=File.open("lengyel.txt","r")
g=File.new("dtim1806_F3_ki.txt","w")
lines=f.readlines
lines.each do |line|
  #minden muvelet elott uritjuk a vermet
  v.urit
  line.split(" ").each do |c|
    if c =~ /-?[0-9]+/ #regex szamra
      v.push(c.to_i)
    else #kulonben muvelet
      case c
      when '+'
        x1=v.pop
        x2=v.pop
        v.push(x2+x1)
      when '-'
        x1=v.pop
        x2=v.pop
        v.push(x2-x1)
      when '*'
        x1=v.pop
        x2=v.pop
        v.push(x2*x1)
      when '/'
        x1=v.pop
        x2=v.pop
        v.push(x2/x1.to_f)
      end
    end
  end
  g.write("#{v.pop} \n") #az eredmeny a veremben maradt utolso elem
end
