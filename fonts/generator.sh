#!/bin/bash
set -xe

#gresi na madrid.flf
# and on fourtops
# and usaflag
export LISTOFFILES=$(find ./downloaded_fonts/ -type f)
export NAMESOFFONTS=$(echo "$LISTOFFILES" | sed 's/^.*\///' | cut -d "." -f 1)

echo -e "$NAMESOFFONTS" | parallel 'seq 0 9 | sed "G" | figlet -f ./downloaded_fonts/{}.flf > {}.h' && # generate fonts 0 - 9
echo -e "$NAMESOFFONTS" | parallel 'echo ":" | figlet -f ./downloaded_fonts/{}.flf >> {}.h' &&
echo -e "$NAMESOFFONTS" | parallel 'sed -i "s,\\\,\\\\\\\,g; s,\",\\\\\",g" {}.h' # replace / with // and " with ""
echo -e "$NAMESOFFONTS" | parallel 'sed -i "s/^ *$//g" {}.h' &&  # delete lines with whitespaces
wait
echo -e "$NAMESOFFONTS" | parallel 'awk -v var1={} -f generate_font.awk {}.h > {}.temp' &&
echo -e "$NAMESOFFONTS" | parallel 'mv {}.temp {}.h' &&
wait
echo -e "$NAMESOFFONTS" | parallel 'sed "/^$/N;/^\n$/D" -i {}.h'
echo -e "$NAMESOFFONTS" | parallel 'echo -e "\nconst char* const font_{}[11][VEC_MAXSIZE] = \n{" >> {}.h'
wait
echo -e "$NAMESOFFONTS" | parallel 'grep zero {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep one {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep two[^d][^o][^t][^s] {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep three {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep four {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep five {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep six {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep seven {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep eight {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep nine {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1},\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'grep twodots {}.h | sed "s#const char\* const\(.*\) =.*#\1#" | sed "s#\\n#,#g" | tr "\n" ","  | rev | sed "s/,//" | rev | sed "s/^\(.*\)$/{\1}\n/" | sed "s/^/    /" >> {}.h '
wait
echo -e "$NAMESOFFONTS" | parallel 'echo -e "};" >> {}.h'
wait
echo -e "$NAMESOFFONTS" | parallel 'echo -e "
int calculate_offset_{}(int digit_1, int digit_2);
int offset_before_twodots_{}(int num);
int offset_after_twodots_{}(int num);" >> {}.h'
##
