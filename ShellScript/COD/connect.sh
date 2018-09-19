#! /bin/bash
password="NULL"
SSID="NULL"
conn="NULL"

read_credentials()
{

while read line; do
	if echo $line | grep -q "password" ;
	then
		#echo "password line is"
		password="$(echo $line | awk -F':' '{print $2}')"
	elif echo $line | grep -q "ssid" ;
	then
		#echo "ssid is"
		SSID="$(echo $line | awk -F':' '{print $2}')"
	fi
done<txt

}

connect_wfi()
{
read_credentials
echo "credentials are"
echo $SSID
echo $password
#nmcli device wifi connect GAIATVWIFI++ password gaiatv@8086
nmcli device wifi connect $SSID password $password
}
while true
do
#nmcli device | awk '/wifi/{print $3}' > $conn
conn="$(nmcli device | awk '/wifi/{print $3}')"
echo $conn
if [ "$conn" == "disconnected" ] ; then
	echo "$(date) connection is disconnected"
	connect_wfi
	
else
	#echo $(date)
	echo " $(date) connection is established "
fi
sleep 10
done
