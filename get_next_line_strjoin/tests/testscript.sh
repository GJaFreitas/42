change=$'\nchanging BUFFER_SIZE\n'
echo "Testing Testing:"

cd .. && sh compile.sh 1 && cd tests

for file in *; do
    if [ -f "$file" ]; then
        if [ $file != testscript.sh ]; then
            ../a.out "$file" | cat -e
        fi
    fi
done

echo "$change"

cd .. && sh compile.sh 2 && cd tests

for file in *; do
    if [ -f "$file" ]; then
        if [ $file != testscript.sh ]; then
            ../a.out "$file" | cat -e
        fi
    fi
done

echo "$change"

cd .. && sh compile.sh 42 && cd tests

for file in *; do
    if [ -f "$file" ]; then
        if [ $file != testscript.sh ]; then
            ../a.out "$file" | cat -e
        fi
    fi
done

echo "$change"

cd .. && sh compile.sh 100 && cd tests

for file in *; do
    if [ -f "$file" ]; then
        if [ $file != testscript.sh ]; then
            ../a.out "$file" | cat -e
        fi
    fi
done

echo "$change"

cd .. && sh compile.sh 1000 && cd tests

for file in *; do
    if [ -f "$file" ]; then
        if [ $file != testscript.sh ]; then
            ../a.out "$file" | cat -e
        fi
    fi
done

wrongfd=$'\nok now for invalid files\n'

echo "$wrongfd"

../a.out bleh
