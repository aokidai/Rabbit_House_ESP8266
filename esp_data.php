<?php
	include("../include/connect.inc");
	$api_key_value = "kjsjkhjdhfd";
	$api_key= $sensor = $location = $value1 = $value2 = $mua = "";
	date_default_timezone_set('Asia/Ho_Chi_Minh');
	$time_act = date('Y-m-d H:i:s');
	var_dump($_POST);
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$api_key = test_input($_POST["api_key"]);
		if($api_key == $api_key_value) {
			$sensor = test_input($_POST["sensor"]);
			$location = test_input($_POST["location"]);
			$value1 = test_input($_POST["value1"]);
			$value2 = test_input($_POST["value2"]);
                        $mua = test_input($_POST["mua"]);
                        $dudoanmua = "";
                        if($value1<=27 && $value2>86)
                                $dudoanmua = "Có mưa";
                        else $dudoanmua = "Không mưa";
			$sql = "INSERT INTO SensorData (sensor, location, value1, value2, time_act, mua, dudoanmua) VALUES ('" . $sensor . "', '" . $location . "', '" . $value1 . "', '" . $value2 . "', '" . $time_act . "', '" . $mua . "', '" . $dudoanmua . "')";
			$rs = mysqli_query($conn, $sql);
			if($rs){
				echo "New record created successfully";
			} 
			else {
				echo "Error: " . $sql . "<br>" . $conn->error;
			}
		}
		else {
			echo "Wrong API Key provided.";
		}
	}
	else {
		echo "No data posted with HTTP POST.";
	}
function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>
