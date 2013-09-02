<?php

        $postData = file_get_contents("php://input"); 
        error_log($postData); 
        $postData = $postData."\r\n" ;
        $length = strlen($postData);
        

        $ch = curl_init();
        $user_agent = "Mozilla/5.0 (Windows NT 6.1; rv:22.0) Gecko/20130405 Firefox/22.0" ;
        $apiUrl = "http://yuktix01.cloudapp.net:8080/sensordb/v1/account/add" ;

        error_log($apiUrl);

        curl_setopt ($ch, CURLOPT_USERAGENT, $user_agent);
        curl_setopt ($ch, CURLOPT_TIMEOUT, 30);
        curl_setopt ($ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt ($ch, CURLOPT_FOLLOWLOCATION, 1);

        $headers = array( "Content-Type: application/json; charset=UTF-8", "Content-Length: ".$length);
        
        curl_setopt($ch,CURLOPT_HTTPHEADER,$headers);
        curl_setopt ($ch, CURLOPT_URL, $apiUrl);
        curl_setopt ($ch, CURLOPT_POSTFIELDS, $postData);
        curl_setopt ($ch, CURLOPT_POST, 1);
        
        $result = curl_exec ($ch);
        $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        $responseObj = json_decode($result);

        $data = array();

        if($http_code == 200) {
            $data = array("message" => "success", "code" => $responseObj->code, "accountId" => $responseObj->response->accountId);
        } else {
            $data = array("message" => "error", "code" => $responseObj->code, "accountId" => $responseObj->response->accountId);
        }

        echo json_encode($data);

?>
