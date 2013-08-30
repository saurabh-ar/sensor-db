<?php

 $token = null ;
 if(array_key_exists("token",$_REQUEST)) {
	 $token = $_REQUEST["token"] ;
 }
 
 sleep(7);
 
 if($token != null ) {
  $token = strrev($token);
  echo $token ;
 } else {
  echo "supply a token!" ;
 }
 


?>
