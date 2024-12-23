[!] THE NEW VALUES MUST BE IN THE FORMAT OF THE prefTitle + Var. EX. kbUseVar = kbUse [/!]
[Function name=J_AddPreference]
	[text multi=T]noItem=0&err=F[/text]
	[Showif [isNull varName=p_itemID]=T][text]noItem=1[/text][/Showif]
	[Showif [GetChars start=1&trim=both]
		[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=INSERT INTO Preferences
		(
			r_defPref,
			prefVal,
			[Hideif [noItem]=1]r_itemid,[/Hideif]
			r_ownerid,
			datecreated,
			datemodified,
			createdby,
			modifiedby,
			prefType
		)
		OUTPUT
			INSERTED.SKU AS skuvarNEW,
			INSERTED.DATECREATED AS datecreatedVar,
			INSERTED.DATEMODIFIED AS datemodifiedvar
		values (
			'[p_defSku]',
			'[CleanVar varName=p_Value]',
			[Hideif [noItem]=1]'[p_itemID]',[/Hideif]
			'[ownerVar]',
			'[date] [time]',
			'[date] [time]',
			'[techskuvar]',
			'[techskuvar]',
			'[p_type]'
		);]
		[/SQL][/getchars]!]
			[text]err=T[/text]
	[/Showif]
	[RETURN][err][/RETURN]
[/Function]

[Function name=J_UpdatePreferenceRecord]
	[text multi=T]noItem=0&err=F[/text]
	[Showif [isNull varName=p_itemID]=T][text]noItem=1[/text][/Showif]
	[Showif [GetChars start=1&trim=both]
		[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=UPDATE Preferences
			set
			prefVal = '[CleanVar varName=p_Value]',
			datemodified = '[date] [time]',
			modifiedby = '[techskuvar]'
			OUTPUT
				INSERTED.DATEMODIFIED AS datemodifiedvar
			WHERE r_ownerid = '[ownerVar]' AND sku = '[p_editSku]' AND prefType = '[p_type]'[Hideif [noItem]=1] AND r_itemid = '[p_itemID]'[/Hideif];]
		[/SQL][/getchars]!]
			[text]err=T[/text]
	[/Showif]
	[RETURN][err][/RETURN]
[/Function]

[Function name=J_UpdatePreference]
	[text]err=F[/text]
	
	[text]defSku=[/text]
	[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=SELECT TOP (1) sku FROM sys_PrefDefaults WHERE prefTitle = '[CleanVar varName=p_prefTitle]';]
		[Founditems]
			[text]defSku=[sku][/text]
		[/Founditems]
		[Showif [numfound]=0]
			[text]err=T[/text]
		[/Showif]
	[/SQL]
			
	[SQL DSN=[dbcatalog]&username=[dbuservar]&password=[dbpassvar]&statement=SELECT TOP (1) sku FROM Preferences WHERE r_defPref = '[defSku]' AND r_ownerid = '[ownerVar]' AND prefType = 'sys_PrefDefaults' [Hideif [isNull varName=p_itemid]=T] AND r_itemID = '[p_itemid]'[/Hideif];]
		[Founditems]
			[text]skuvar=[sku][/text]
		[/Founditems]
	[/SQL]

	[text]theValue=[p_prefValue][/text]
	
	[Hideif [err]=T]
		[IF ("[isNull varName=skuvar]"="T"]
			[THEN]
				[!] INSERT [/!]
				[text]err=[J_AddPreference p_type=sys_PrefDefaults&p_defSku=[defSku]&p_Value=[URL][theValue][/URL][Hideif [isNull varName=p_itemid]=T]&p_itemid=[p_itemid][/Hideif]][/text]
			[/THEN]
			[ELSE]
				[!] UPDATE [/!]
				[text]err=[J_UpdatePreferenceRecord p_type=sys_PrefDefaults&p_editSku=[skuvar]&p_Value=[URL][theValue][/URL][Hideif [isNull varName=p_itemid]=T]&p_itemid=[p_itemid][/Hideif]][/text]
			[/ELSE]
		[/IF]
	[/Hideif]

	[RETURN][err][/RETURN]
[/Function]