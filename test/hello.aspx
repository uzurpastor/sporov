<html>
<head>
</head>
<script language="C#" runat="server">
	void Submit.Btn_Click(Object sendler, EventArgs e){
		Message.Text = "hello";
	}
</script>
<body>
<center>
<form method="post" runat="server">
<asp:button type=submit text="hello" OnClick="SubmitBtn_Click"
runat="server"/><br>
<asp:label id="Message" runat="server"/>
</form>
</center>
</body>
</html>