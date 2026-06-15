echo "[TEST] multi-file d"
printf "aaaaa" > a.txt
printf "bbbbb" > b.txt
printf "cccccccccc" > c.txt
echo "input files: a.txt b.txt c.txt"

echo " zipping "
./my-zip a.txt b.txt c.txt > test.z
echo "PASSED"
echo " unzipping "
./my-unzip test.z > out.txt
echo "PASSED"
cat a.txt b.txt c.txt > expected.txt
diff expected.txt out.txt

if [ $? -eq 0 ]; then
    echo "PASSED"
else
    echo "FAILED"
fi