//
//  getCount.php
//  PCT/MySQL_server
//
//  Created by Israel Arroyo on 18/12/20.
//
<?php
    // updates entry if there is an entry with the same id and current date
    // adds entry if there is no such entry with id and current date
    $machineID = $_GET ['id'];
    $today = date("d/m/Y"); // 19/12/2020
    $user = "client1";
    $password = "HolaMundo";
    $server = "localhost";
    $database = "PCT";
    
    $connection = mysqli_connect($server, $user, $password) or die ("Unable to establish connection with DB server");
    
    $db = mysqli_select_db($connection,$database) or die ("Unable to establish connection with DB");
    
    $count = "SELECT * FROM Entries";

    $result = mysqli_query($connection, $count) or die ("Error in check date query");



    if ($result->num_rows > 0)
    {
      // output data of each row
      while($row = $result->fetch_assoc())
      {
        echo "Máquina: " . $row["machineID"]. " - Fecha: " . $row["printDate"]. " Cartas impresas:" . $row["cardsPrinted"]. "<br>";
      }
    }
    else
    {
      echo "0 results";
    }
    $conn->close();
?>
