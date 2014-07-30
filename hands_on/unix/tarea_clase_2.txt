tar -xvzf measurements.tgz 
cd measurements/
ls | wc -l
wc -l * > conteo.dat
mkdir bien
awk < conteo.dat '{if($1==24) print "mv " $2 " bien/"}' > mover.sh
chmod u+x mover.sh 
./mover.sh 
mkdir mal
mv measurement_station_* mal
