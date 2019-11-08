<?php
$servername="localhost";
$dbname="lost";
$username="tempuser";
$password="shrish@23";

$mysqli=new mysqli($servername,$username,$password,$dbname);

if ($mysqli->connect_error) {
	die("[Error] connection failed" .$mysqli->connect_error);
}
else{
	echo "success";
}
?>