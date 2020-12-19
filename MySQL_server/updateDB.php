//
//  index.php
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
    
    $checkDate = "SELECT cardsPrinted FROM Entries WHERE printDate = '".$today."' AND machineID = ".$machineID;

    
    $result = mysqli_query($connection, $checkDate) or die ("Error in check date query");
    if($result->num_rows == 0)
    {
        $insert ="INSERT into PCT.Entries (printDate,machineID,cardsPrinted) VALUES('".$today."',".$machineID.",1)";
        $insertResutl = mysqli_query($connection, $insert) or die ("Error in insert query");
        
    }
    else
    {
        $update = "UPDATE Entries SET cardsPrinted=cardsPrinted + 1 WHERE printDate = '".$today."' AND machineID = ".$machineID;
        $insertResutl = mysqli_query($connection, $update) or die ("Error in update query");
    }
    
    ?>
