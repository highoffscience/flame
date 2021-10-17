<?php
  if ($_SERVER['REQUEST_METHOD'] == 'POST')
  {
    //$cmd_line_args_s = "";
    //foreach ($_POST as $key=>$value)
    //{
    //  $cmd_line_args_s .= "--$key $value ";
    //}
    //
    //shell_exec("rm -f ./pics/*");
    //$output = shell_exec("./Debug/Fractal $cmd_line_args_s"); // ; echo $?
    //$data = array('Time'=>$output);
    //echo json_encode($data);
    echo "Why, hello there!";
  }
  else
  {
    echo "-1";
  }
?>

