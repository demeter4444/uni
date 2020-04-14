str2="The Flesch-Kincaid readability  tests are readability tests designed to indicate how difficult a passage in  English is to understand. There are two tests, the Flesch Reading Ease, and the Flesch-Kincaid Grade Level. Although they use the same core measures (word length and sentence length), they have different weighting factors.The results of the two tests correlate approximately inversely: a text with a comparatively high score on   the Reading Ease test should have a lower score on the Grade-Level test. Rudolf Flesch devised the Reading Ease evaluation; somewhat later, he  and J . Peter Kincaid developed the Grade Level evaluation for the United States Navy"
str1 = "One day a deer was born. His name was Bambi.  His mother washed him all over with her tongue. Bambi , she said.  My little Bambi. The young Bambi was curious about  everything.  He learned  he was a deer, and so was his mother.  He learned there are other deer in the forest, and someday he would meet them. He learned the trails his mother followed were made by the deer. Bugs and critters, sounds and smells. So many wonders to explore! Sometimes on a trail, suddenly  his mother would stop still.  She would open her ears wide and listen from all directions. First- over there! Then- here!  Bambi would wait.  At last, when she said, It’s all right.  There’s no danger. We can go, then the two of them would start on the trail again.  But he did not know why they had to do this"
szavak1 = str1.split(/[,:;.?!\- ]+/).size #split minden leheto legtobb egymast koveto akarmilyen kombinacioban elehelyezkedo szoelvalaszto szerint (regex)
szavak2 = str2.split(/[,:;.?!\- ]+/).size
mondatok1 = str1.split(/[.?!]+/).size #ugyanaz mondatelvalasztora
mondatok2 = str2.split(/[.?!]+/).size
szotagok1=0
szotagok2=0

str1.each_char {
    |x| if x =~ /[aeiouAEIOU]+/ #maganhangzo ellenorzes regexxel
          szotagok1 +=1
        end
  }

str2.each_char {
    |x| if x =~ /[aeiouAEIOU]+/ #-||-
          szotagok2 +=1
        end
}

felsch1=206.835-1.015*(szavak1/mondatok1.to_f)-84.6*(szotagok1/szavak1.to_f)
felsch2=206.835-1.015*(szavak2/mondatok2.to_f)-84.6*(szotagok2/szavak2.to_f)

puts "Elso szoveg Felsch(Bambi): #{felsch1}"
puts "Masodik szoveg Felsch(Felsch): #{felsch2}"