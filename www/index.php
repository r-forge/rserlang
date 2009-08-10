
<!-- This is the project specific website template -->
<!-- It can be changed as liked or replaced by other content -->

<?php

$domain=ereg_replace('[^\.]*\.(.*)$','\1',$_SERVER['HTTP_HOST']);
$group_name=ereg_replace('([^\.]*)\..*$','\1',$_SERVER['HTTP_HOST']);
$themeroot='http://r-forge.r-project.org/themes/rforge/';

echo '<?xml version="1.0" encoding="UTF-8"?>';
?>
<!DOCTYPE html
	PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en   ">

  <head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<title><?php echo $group_name; ?></title>
	<link href="<?php echo $themeroot; ?>styles/estilo1.css" rel="stylesheet" type="text/css" />
  </head>

<body>

<!-- R-Forge Logo -->
<table border="0" width="100%" cellspacing="0" cellpadding="0">
<tr><td>
<a href="/"><img src="<?php echo $themeroot; ?>/images/logo.png" border="0" alt="R-Forge Logo" /> </a> </td> </tr>
</table>


<!-- get project title  -->
<!-- own website starts here, the following may be changed as you like -->

<?php if ($handle=fopen('http://'.$domain.'/export/projtitl.php?group_name='.$group_name,'r')){
$contents = '';
while (!feof($handle)) {
	$contents .= fread($handle, 8192);
}
fclose($handle);
echo $contents; } ?>
<p> The package is now publicly accessible from the SVN repository. </p>
<!-- end of project description -->
<h2>What is rErlang?</h2>
<p>Erlang/OTP is programming language and runtime environment which supports concurrency, scalability, and fault-tolerant.Erlang/OTP have many modern distributed computing features but are let down by that weakness numerical computation and mathematical libraries. RErlang project improve this weakness by using R facilities.</p>
To communicate with R, Erlang ports (Ports) and OTP standard behaviors are used in Erlang side.
Ports provide a byte-oriented interface to an external program.
And also we want to ensure that rErlang is robust in the event that the external problems or does not respond in a timely manner. The use of standard OTP enables us to do so with minimal effort.
<h2>What's new?</h2>
<table>
<tr valign=top><td><b>2009/08/05</b></td><td>Project is registered</td></tr>
</table>
<h2>Features of rErlang</h2>
<p>Coming Soon !</p>
<p>This project is just getting started. <a href="http://r-forge.r-project.org/project/request.php?group_id=499">Please join us!</a></p>
</body>
</html>
