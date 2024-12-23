[Function name=J_INSERT_PRIV_FUNC]
	[RETURN]('[skuvar]','[date] [time]','[techskuvar]','[privSku]')[/RETURN]
[/Function]

[Function name=J_INSERT_PRIV]
	[text]err=T[/text]
	[Showif [GetChars start=1&trim=both]
		[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=INSERT INTO core_Login_Priv
		(
			r_loginID,
			datecreated,
			createdby,
			r_privtype
		) values (
			'[skuvar]',
			'[date] [time]',
			'[techskuvar]',
			'[privSku]'
		);]
		[/SQL][/GetChars]=]
			[text show=t]err=F[/text]
	[/Showif]
	[RETURN][err][/RETURN]
[/Function]

[Function name=J_DELETE_PRIV]
	[text]err=T[/text]
	[Showif [GetChars start=1&trim=both]
		[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=DELETE FROM core_Login_Priv 
			WHERE r_privType = '[privSku]' AND r_loginID = '[loginSku]' AND sku = '[skuvar]';]
		[/SQL][/GetChars]=]
			[text show=t]err=F[/text]
	[/Showif]
	[RETURN][err][/RETURN]
[/Function]