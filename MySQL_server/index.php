<!DOCTYPE html>
<?php
    date_default_timezone_set('America/Mexico_City');
    $today = date("d/m/Y"); // 19/12/2020
    $user = "id15714716_root";
    $password = "~Igt_&RR!o]&o8E|";
    $server = "localhost";
    $database = "id15714716_pct";
    $connection = mysqli_connect($server, $user, $password) or die ("Unable to establish connection with DB server");
    $db = mysqli_select_db($connection,$database) or die ("Unable to establish connection with DB");
    $count = "SELECT * FROM Entries WHERE printDate = '".$today."'";
$result = mysqli_query($connection, $count) or die ("Error in check date query");
    ?>
<html>
<head>
  <style>
  h1
  {
    text-align:center;
  }
  body
  {
    background-color:#000;
    color:white;
    font-size:30px
  }
</style>
</head>
<body>
    <h1>Tarjetas contadas</h1>
<center><?php     if ($result->num_rows > 0)
    {
      // output data of each row
      while($row = $result->fetch_assoc())
      {
        echo "<h2>Máquina " . $row["machineID"].
        ": </h2><h3><div style='width:500px;height:50px;border:1px solid #FFFFFF;'>".
        $row["cardsPrinted"]." tarjetas"."</div><br></h3>";
      }
    }
    else
    {
      echo "0 resultados";
    }
    $connection->close();
    ?></center>
</body>
</html>
