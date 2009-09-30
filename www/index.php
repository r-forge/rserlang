
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
<p>Erlang/OTP is programming language and runtime environment which supports concurrency, scalability, and fault-tolerant.Erlang/OTP have many modern distributed computing features but are let down by that weakness numerical computation and mathematical libraries. rErlang project improve this weakness by using R facilities.</p>
To communicate with R, Erlang ports (Ports), ei (Erlang Interface) library and OTP standard behaviors are used in Erlang side.
Ports provides a byte-oriented interface to an external program. ei helps conversion of data between C and Erlang formats.
And also we want to ensure that rErlang is robust in the event that the external problems or does not respond in a timely manner. The use of standard OTP enables us to do so with minimal effort.
<h2>What's new?</h2>
<table>
<tr valign=top><td><b>2009/08/05</b></td><td>Project is registered</td></tr>
</table>
<h2>Features of rErlang</h2>
<p>Coming Soon !</p>
<p>This project is just getting started. <a href="http://r-forge.r-project.org/project/request.php?group_id=499">Please join us!</a></p>

<h2>Binding rules of data types between R and Erlang</h2>
<p>Coming Soon !</p>

<h2>Tutorial</h2>
<h3>Erlang -> R</h3>
</td></tr></table>
<table border=0 width=100%><tr><td>
<table bgcolor=black width=100% border=1 cellspacing=0><tr><td><font color=white><pre>
usr@home: erl
Erlang (BEAM) emulator version 5.6.3 [source] [smp:2] [async-threads:0] [kernel-poll:false]

Eshell V5.6.3  (abort with ^G)
1> eri:start().
<0.33.0>
2> eri:connect().
{ok,0}
3> eri:eval("1:9").
{ok,'INTSXP',[1,2,3,4,5,6,7,8,9]}
4> {ok, Type, Result} = eri:eval("rnorm(10)").
5> Type.  
'REALSXP'
6> Result.
[-0.1917861903879111,1.0077673823951807,0.05707066688405165,
 -1.7174303197492615,0.6188926676115155,0.25904560550869155,
 0.5981845165498236,-0.4449771878757933,1.0737026013065656,
 0.22614169517088667]
</pre></font></td></tr></table>
</td></tr></table>
<h3>R -> Erlang</h3>
<table border=0 width=100%><tr><td>
<table bgcolor=black width=100% border=1 cellspacing=0><tr><td><font color=white><pre>
</pre></font></td></tr></table>

</body>
</html>
