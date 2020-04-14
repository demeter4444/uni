#Demeter Tamas
#dtim1806
#511/2
#F4 paratlan

class Elem #egy elem tulajdonsagai : adat(ip cim), rakovetkezo
  attr_accessor :data, :nxt
  def initialize(x) #kontruktor
    @data=x
    @nxt=nil
  end
end

class Lista #az @-el jelolt elemek class-on beluliek.
  #lista adattagjai: maga a lista, egyedi felhasznalok szama, rendszeres felhasznalok szama
  def initialize
    @elemek=[]
    @egyedi=0
    @rendszeres=0
  end

  def insert(data, pos = @elemek.length) #elem hozzaadasa listahoz
    elem=Elem.new(data)
    #beteves elott megnezzuk ha szerepel-e mar az adott listaban, ha nem akkor noveljuk az "egyedi"-t
    @egyedi+=1
    @elemek.each do |i|
      if i.data == data
        @egyedi-=1
        break
      end
    end
    #lista elejere beszuras
    if pos <=0
      elem.nxt=@elemek[0].nxt if @elemek.length>0
      @elemek.insert(0,elem)
      #lista vegere beszuras
    elsif pos >= @elemek.length
      @elemek[-1].nxt=elem.object_id if @elemek.length>0
      @elemek.push(elem)
      #adott poziciora beszuras
    else
      elem.nxt=@elemek[pos-1].nxt
      @elemek[pos-1].nxt=elem.object_id
      @elemek.insert(pos, elem)
    end
  end
  #lista kiirasa metodus
  def kiir
    @elemek.each do |i|
      puts "#{i.data}"
    end
  end
  #getter fuggveny az egyedi adattagra (alapbol privat a ruby-ban, tudtom szerint)
  def getegyedi
    @egyedi #return kulcsszo elhagyhato
  end
  #rendszeres felhasznalok szamolasa egy listaban
  def szamolrendszeres(k)
    rendszeresek=0
    if @elemek.length >= k #csak akkor kezdjuk nezni ha egyaltalan lehetseges, hogy legyen rendszeres felhasznalo
      @elemek.each do |i|
        sum=0
        @elemek.each do |j|
          sum +=1 if j.data==i.data
        end
        sum-=1
        rendszeresek=1 if sum >= k #az ifet lehet forditva is irni
      end
    end
   rendszeresek #return
  end

end

cimek=[] #ez a tomb lesz a hash-tablank. ennek elemei listak.
f=File.open("cimek.txt","r")
g=File.open("output.txt","w")

#beolvassuk a file sorait. a sorok egy tombbe kerulnek, ahol minden elem egy masik sor.
lines=f.readlines
lines.shift #az n nem erdekel
k=lines[0].to_i #a k-t kiolvassuk
lines.shift #most a tombunk csak a jelentos sorokat tartalmazza
lines.each do |x|

  #ez a hasitofuggvenyunk:
  # minden ip-cimet felbontunk . szerint, az elemeket pedig osszeadjuk.
sum=0
  x.split(".").each do |i|
    sum+=i.to_i
  end
  if cimek[sum] #ha mar letrehoztunk egy adott indexen listat, akkor hozzafuzzuk
    cimek[sum].insert(x)
  else #ha nem, letrehozzuk
    cimek[sum]=Lista.new
  end
end

sumegyedi=0
sumrendszeres=0
#miutan megvan a hashtablank, bejarjuk, s meghatarozzuk az egyedi es rendszeres felhasznalok szamat.
cimek.each do |i|
  if i
    sumegyedi+=i.getegyedi
    sumrendszeres+=i.szamolrendszeres(k)
  end
end

puts "#{sumegyedi} egyedi felhasznalo"
puts "#{sumrendszeres} rendszeres felhasznalo"

g.puts "#{sumegyedi} egyedi felhasznalo"
g.puts "#{sumrendszeres} rendszeres felhasznalo"

f.close
g.close

#megj
# utolag belegondolva lehet kellett volna kulon osztalyt irjak maganak a hash tablanak, mert jelenleg csak egy standard tomb az egesz.
# ez csak annyival tenne szebbe, hogy az egyedi es rendszeres szamolo metodusokat nem a tabla minden elemere(listajara) hivom meg a "foprogramba",hanem egy osztalyon belul. vehetjuk ugy, hogy a foprogram maga a hash osztaly.