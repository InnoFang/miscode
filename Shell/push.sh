echo "----------Begin----------" 
echo " +--- start pulling ---+"
git pull origin master
echo " +---  end  pulling ---+"
echo " +--- start adding ---+"
git add .
echo " +---  end  adding ---+"
echo " +--- start commiting ---+"
git commit -m "$*"
echo " +--- commit message as below ---+"
echo $*
echo " +---  end  commiting ---+"
echo " +--- start pushing ---+"
git push origin master
echo " +---  end  pushing ---+"
echo "---------- End ----------"