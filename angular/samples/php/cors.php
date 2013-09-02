<?php

        $json = json_decode(file_get_contents("php://input")); 
        echo $json->token ;

        $ch = curl_init();
        $user_agent = "Mozilla/5.0 (Windows NT 6.1; rv:22.0) Gecko/20130405 Firefox/22.0" ;
        $apiUrl = "http://yuktix01.cloudapp.net:8080/sensordb/v1/echo/" ;
        $apiUrl .= $json->token ;

        error_log($apiUrl);

        curl_setopt ($ch, CURLOPT_USERAGENT, $user_agent);
        curl_setopt ($ch, CURLOPT_TIMEOUT, 30);
        curl_setopt ($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt ($ch, CURLOPT_FOLLOWLOCATION, 1);

        $headers = array( "Content-Type: text/plain; charset=UTF-8");
        
        curl_setopt($ch,CURLOPT_HTTPHEADER,$headers);
        curl_setopt ($ch, CURLOPT_URL, $apiUrl);

        $result = curl_exec ($ch);
        $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);

        $response = array("response" => $result , "code" => $http_code ); 
        $data = json_encode($response);
        error_log($data);
        echo $data ;

?>
