find . -name "*.sh" -type f|awk -F '/' '{print $NF}'|awk -F '.' '{print $1}'
