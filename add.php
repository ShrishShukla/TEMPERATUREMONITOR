<?php
include('util-dbconn.php');
if(isset($_GET['temperature'])){
	echo "GET is working";
}
else{

	echo "GET DIDN'T WORK FOR VARIABLE";
}

$temperature=$_GET['temperature'];
echo $temperature;
echo "\n";


echo "[DEBUG] Temperature sensor data :" .$temperature ."\n";
$sql=" INSERT INTO `garmi` (`tapman`) VALUES (".$temperature.") ";
if(!$result = $mysqli->query($sql) ){
	echo "[ERROR]" . mysqli_error($mysqli) . "\n";
	echo "we were in the db";
	exit();

}
$mysqli->close();
echo "temperature data added successfully.\n";
?>