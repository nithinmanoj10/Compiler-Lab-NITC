!/bin/zsh

cd '/mnt/d/Nithin Stuff/Sem 6/Compiler Lab/Compiler-Lab-NITC'

clear
echo "š Pushing Files ā” nithinmanoj10/Compiler-Lab-NITC ...\n"

# Adding all the files
git add -A

printf '%.sā' $(seq 1 $(tput cols))
git status
printf '%.sā' $(seq 1 $(tput cols))

printf "\nš Enter Commit Message: "
read commitMessage
printf "\n"

git commit -m "$commitMessage"
printf '%.sā' $(seq 1 $(tput cols))

# git push origin master

printf "nithinmanoj10\n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\n" | git push origin master
printf '%.sā' $(seq 1 $(tput cols))
