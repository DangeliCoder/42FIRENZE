FT_USER=bocal
groups $FT_USER|awk -F ': ' '{print $2}'|tr ' ' ','|cat -e
