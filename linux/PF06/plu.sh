nap=`echo $1 | grep -o "^[0-9]\{2\}"`

month=`date +"%m"`
#day=`date +"%e"`
case $month in
  01) month="Jan";;
  02) month="Feb";;
  03) month="Mar";;
  04) month="Apr";;
  05) month="May";;
  06) month="Jun";;
  07) month="Jul";;
  08) month="Aug";;
  09) month="Sep";;
  10) month="Oct";;
  11) month="Nov";;
  12) month="Dec";;
esac

last | grep " $month $nap" | sort >seged1.tmp
grep -o '^[a-z0-9_]\+' seged1.tmp | uniq
rm seged1.tmp

exit 0

