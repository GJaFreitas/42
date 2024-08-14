echo ""
echo "Correct output:"
"cat" -e $1
echo ""
echo "My output:"
./program $1 | "cat" -e
echo ""
