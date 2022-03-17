grep -v '^#' /etc/passwd | awk -F ':' 'NR%2==0 {print $1}' | rev | sort -r | awk -v l1=$FT_LINE1 -v l2=$FT_LINE2 '( l1 <= NR && NR <= l2 ) {printf "%s%s", $0, (NR < l2 ? "," : "." )}' | cat -e
