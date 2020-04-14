class Ritka

  def initialize(a,m,n)
    #elmentjuk/inicializaljuk a matrix eredeti mereteit, a 4+2 vektorunkat s ezek meretet. (elso 4nek @@@n, utolso 2nek m,n)
    @n=n
    @m=m
    @sor=[]
    @oszlop=[]
    @ertek=[]
    @kovindex=[]
    @sindex=[]
    (0...m). each {|x| @sindex[x]=-1}
    @oindex=[]
    (0...n). each {|x| @oindex[x]=-1}
    @tempo=[]
    (0...n). each {|x| @tempo[x]=-1}
    @nnn=0

    ##a matrix alapjan inicializaljuk a 4+2 vektort
    (0...m).each do |x|
      (0...n).each do |y|
        if a[x][y] != 0
          @sor[@nnn]=x
          @oszlop[@nnn]=y
          @ertek[@nnn]=a[x][y]
          @kovindex[@nnn]=-1
          if @tempo[y]!=-1 then  @kovindex[@tempo[y]]=@nnn else @tempo[y]=@nnn end #tempo = az elso megtalalt elem egy oszlopban
          if @sindex[x]==-1 then @sindex[x] = @nnn end
          if @oindex[y]==-1 then @oindex[y] = @nnn end
          @nnn +=1
          end
      end
    end
  end

  #visszateriti az i,j koordinatakon elhelyezkedo elemet
  def getElem(i,j)
    #elindulunk az adott oszlop elso elemetol
    tempo=@oindex[j]
    #ha ez az eleme eleve rossz, vagy nem lehet ritka elem, ezt hamar visszateritjuk
    if i>=@m || j>=@n then return -999 end
    if tempo==-1 then return 0 end
  #kulonben keressuk a sorindexet
    (@oindex[j]...@nnn).each do |x|
      if @sor[x]==i then return @ertek[x] end
    end
    return 0

    end

  def kiir
  #kiirjuk a vektorainkat
    puts "SOR = #{@sor}"
    puts "OSZLOP = #{@oszlop}"
    puts "ERTEK = #{@ertek}"
    puts "KOVINDEX = #{@kovindex}"
    puts "S = #{@sindex}"
    puts "O = #{@oindex}"
    puts "tO = #{@tempo}"
  end

  def kiir_matrix
  #kiirjuk a matrixot
    i = 0
    (0...@m).each do |x|
     (0...@n).each do |y|
       if @sor[i]==x && @oszlop[i]==y
        printf("%d ",@ertek[i])
         i+=1
       else printf("0 ")
       end
     end
      printf("\n")
    end
  end

  def kiir_sor
    #a vektorelemek eleve a sorok sorrendjebe kovetkeznek, szoval eleg kiirni sorba az ertekeket.
    puts "#{@ertek}"
  end

  def kiir_oszlop
    #az oszlopnal felhasznaljuk a kovindex es oszlop-elso-eleme-index vektorokat
    # addig amig ki nem irattunk minden elemet atadjuk az oszlop-elso-eleme-indexet egy valtozonak. ha ez az elem letezik (nem -1) kiirjuk s atadjuk a valtozonak az oszlop kovetkezo elemenek indexet a "kovindex" vektorbol
    # amennyiben egy oszlopban nincs tobb elem, az emlitett valtozo a kovetkezo oszlop elso elemenek indexet kapja.
    count = 0
    i = 1
    aktoszlop=@oindex[0]
    while count < @nnn do
      if aktoszlop == -1  ; aktoszlop=@oindex[i] ; i+=1
      else
        printf("%d ",@ertek[aktoszlop])
        aktoszlop=@kovindex[aktoszlop]
        count +=1
      end
    end
  end

end

t = Time.now
f = File.open("dtim1806_F2_be.txt","r")
lines = f.readlines
m, n = lines[0].split(" ").map &:to_i
a = []
(0...m).each do |x|
  a[x]=lines[x+1].split(" ").map &:to_i
end

r=Ritka.new(a, m, n)
puts "Vektorok kiiratasa"
r.kiir
begin
puts "Matrix kiiratasa"
r.kiir_matrix
puts "Lekert elem kiiratasa"
puts r.getElem(1,1)
puts "Ritka elemek soronkent"
r.kiir_sor
puts "Ritka elemek oszloponkent"
r.kiir_oszlop
puts "\nFutasi ido: #{Time.now-t}s"
end