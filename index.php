<!DOCTYPE html>
<html>
<script type="text/javascript">
    init_reload();
    function init_reload(){
        setInterval( function() {
                   window.location.reload();
 
          },1000);
    }
</script>
<body>
	<table align="center">
                        <tr align="center">
                                <th><center><span style="textalign:center">Bảng kiểm tra nhiệt độ độ ẩm</span></center></th>
                        </tr>
			<tr>
				<td>STT</td>
				<td>Vị trí</td> 
				<td>Nhiệt độ</td> 
				<td>Độ ẩm</td>
                                <td>Mưa</td>
				<td>Thời gian</td>
                                <td>Dự báo mưa</td>
			</tr>

			<?php
				include("../include/connect.inc");
				$sql = "SELECT * FROM SensorData ORDER BY id DESC";
				$rs = mysqli_query($conn, $sql);
                                $count		=	mysqli_num_rows($rs);
                                $pageSize = 50;
                                $pos 		=	(!isset($_GET["page"]))?0:($_GET["page"] -1)*$pageSize;	
                                $sql		=	"select * from SensorData ORDER BY id DESC limit $pos, $pageSize";
                                $rs 		=	mysqli_query($conn, $sql);
				$i = 1;
				while($row=mysqli_fetch_array($rs)){
					echo "<tr>
						<td>$i</td>
						<td>".$row["location"]."</td>
						<td>".$row["value1"]."</td>
						<td>".$row["value2"]."</td>
                                                <td>".$row["mua"]."</td>
						<td>".$row["time_act"]."</td>
                                                <td>".$row["dudoanmua"]."</td>
						</tr>";
                                        
                                        if($i>=20){
                                                $sql2 = "delete from SensorData";
                                                $rs2 = mysqli_query($conn, $sql2);
                                        }
					$i++;
                                        
				}
			?>
	</table>
</body>
</html>