[!] ============================= [/!]
[!]  Convert Base64 to Base64url  [/!]
[!] ============================= [/!]
[Function name=JWT_B64toB64url]
[TABLE name=DNA_CONVERT&fields=from,to]
%2B	-
%2F	_
%3D	
[/TABLE]
    [RETURN][CONVERTCHARS table=DNA_CONVERT][string][/CONVERTCHARS][/RETURN]
[/Function]

[!] ============================= [/!]
[!]  Convert Base64url to Base64  [/!]
[!] ============================= [/!]
[Function name=JWT_B64urltoB64]
[TABLE name=DNA_CONVERT&fields=from,to]
%2D	%2B
%5F	%2F
[/TABLE]
    [RETURN][CONVERTCHARS table=DNA_CONVERT][string][/CONVERTCHARS][/RETURN]
[/Function]

[!] ============================= [/!]
[!] Encrypts a String with Base64 [/!]
[!] ============================= [/!]
[Function name=JWT_EncryptBase64]
	[RETURN][Encrypt method=Base64][string][/Encrypt][/RETURN]
[/Function]

[!] ============================= [/!]
[!] Decrypts a String with Base64 [/!]
[!] ============================= [/!]
[Function name=JWT_DecryptBase64]
	[RETURN][Decrypt method=Base64][string][/Decrypt][/RETURN]
[/Function]

[!] ================================ [/!]
[!] Encrypts a String with Base64url [/!]
[!] ================================ [/!]
[Function name=JWT_EncryptBase64url]
	[RETURN][JWT_B64toB64url string=[URL][Encrypt method=Base64][string][/Encrypt][/URL]][/RETURN]
[/Function]

[!] ================================ [/!]
[!] Decrypts a String with Base64url [/!]
[!] ================================ [/!]
[Function name=JWT_DecryptBase64url]
	[RETURN][Decrypt method=Base64][JWT_B64urltoB64 string=[URL][string][/URL]][/Decrypt][/RETURN]
[/Function]

[!] ============================= [/!]
[!] 	    Create Variables	  [/!]
[!] ============================= [/!]
[Function name=JWT_DeclareVars]
[JSONStore table=json_vars]
[json_object]
[/JSONStore]
	[addfields table=json_vars]_dna_sku=1[/addfields]
	[Search table=json_vars&eq_DNA_SKUdatarq=1]
		[numfound]
	[/Search]
	[!]
	[Listwords words=[vars]&delimiters=[del]]
		[text scope=global][word][/text]
	[/Listwords]
	[/!]
[/Function]

[!] ============================= [/!]
[!]  Constructs a default header  [/!]
[!] ============================= [/!]
[Function name=JWT_MakeHeader]
	[text multi=T]_typ=JWT&_alg=HS256[/text]
	[Hideif [typ]=]
		[Hideif [typ]=[RAW][typ][/RAW]]
			[text]_typ=[typ][/text]
		[/Hideif]
	[/Hideif]
	[Hideif [alg]=]
		[Hideif [alg]=[RAW][alg][/RAW]]
			[text]_alg=[alg][/text]
		[/Hideif]
	[/Hideif]
	[RETURN]{"alg":"[_alg]","typ":"[_typ]"}[/RETURN]
[/Function]







[!] ============================= [/!]
[!] 	    Create Variables	  [/!]
[!] ============================= [/!]

[Function name=JWT_DeclareVars]
	[text]del=|[/text]
	[Hideif [delimiters]=]
		[Hideif [delimiters]=[RAW][delimiters][/RAW]]
			[text]del=[delimiters][/text]
		[/Hideif]
	[/Hideif]
	[Listwords words=[vars]&delimiters=[del]]
		[text scope=global][word][/text]
	[/Listwords]
[/Function]

[!] ============================= [/!]
[!] 	  Create Variables 2	  [/!]
[!] ============================= [/!]
[Function name=JWT_DeclareVars2]
	[text scope=global&multi=T][vars][/text]
[/Function]


[!] ============================= [/!]
[!]  Constructs a default header2 [/!]
[!] ============================= [/!]
[Function name=JWT_MakeHeader2]
	[text multi=T]_typ=DNA&_alg=APOP[/text]
	[Hideif [typ]=]
		[Hideif [typ]=[RAW][typ][/RAW]]
			[text]_typ=[typ][/text]
		[/Hideif]
	[/Hideif]
	[Hideif [alg]=]
		[Hideif [alg]=[RAW][alg][/RAW]]
			[text]_alg=[alg][/text]
		[/Hideif]
	[/Hideif]
	[RETURN][URL]alg=[_alg]&typ=[_typ][/URL][/RETURN]
[/Function]

[!] ============================= [/!]
[!]  	Constructs a Signature    [/!]
[!] ============================= [/!]
[Function name=JWT_MakeSignature]
	[RETURN][URL][URL][Encrypt method=[method][Hideif [method]=Base64]&key=[key][/Hideif]][token][/Encrypt][/URL][/URL][/RETURN]
[/Function]

[Function name=JWT_PrintToken]
	[Listwords words=[token]&delimiters=.]
		[Showif [index]=1]
			pheader = [word]<br>
		[/Showif]
		[Showif [index]=2]
			ppayload = [word]<br>
		[/Showif]
		[Showif [index]=3]
			psignature = [word]<br>
		[/Showif]
	[/Listwords]
[/Function]

[!] ============================= [/!]
[!]  	  Compares 2 Strings      [/!]
[!] ============================= [/!]
[Function name=JWT_Compare]
	[Switch value=[Value1]]
		[Case value=[Value2]]
			[RETURN]T[/RETURN]
		[/Case]
		[Default]
			[RETURN]F[/RETURN]
		[/Default]
	[/Switch]
[/Function]

[!] ============================= [/!]
[!]  	     Makes a Token        [/!]
[!] ============================= [/!]
[Function name=JWT_IssueToken]
	[!] ==========Move to Global Var? =========== [/!]
	[text multi=T]_typ=DNA&_alg=APOP[/text]
	[Hideif [alg]=]
		[Hideif [alg]=[RAW][alg][/RAW]]
			[text]_alg=[alg][/text]
		[/Hideif]
	[/Hideif]
	[Hideif [typ]=]
		[Hideif [typ]=[RAW][typ][/RAW]]
			[text]_typ=[typ][/text]
		[/Hideif]
	[/Hideif]
	ALG = [_alg]<br>
	encHeader = [text show=t]encHeader=[JWT_EncryptIt string=[URL][JWT_MakeHeader typ=[_typ]&alg=[_alg]][/URL]][/text]<br>
	encPayload = [text show=t]encPayload=[JWT_EncryptIt string=[URL][payload][/URL]][/text]</br>
	top = [text show=t]top=[encHeader].[encPayload][/text]</br>
	signature = [text show=t]signature=[JWT_MakeSignature method=APOP&key=[key]&token=[URL][top][/URL]][/text]</br>
	token = [text show=t]token=[top].[JWT_EncryptIt string=[URL][signature][/URL]][/text]<br>
	Test = [text show=t]test=[/text]<br>
	[RETURN][URL][token][/URL][/RETURN]<br>
[/Function]

[Function name=JWT_VerifyToken]
	[text multi=t]result=F&pheader=&ppayload=&psignature=[/text]
	[URL][token][/URL]<br>
	[Listwords words=[URL][URL][token][/URL][/URL]&delimiters=.]
		[Showif [index]=1]
			pheader = [text show=t]pheader=[word][/text]<br>
		[/Showif]
		[Showif [index]=2]
			ppayload = [text show=t]ppayload=[word][/text]<br>
		[/Showif]
		[Showif [index]=3]
			psignature = [text show=t]psignature=[word][/text]<br>
		[/Showif]
	[/Listwords]
	[Showif [pheader]!]
		top = [text show=t]top=[pheader].[ppayload][/text]<br>
		[JWT_DeclareVars vars=[JWT_DecryptIt string=[URL][pheader][/URL]]]
		[JWT_DeclareVars vars=[JWT_DecryptIt string=[URL][ppayload][/URL]]]
		sig = [text show=t]sig=[JWT_MakeSignature method=APOP&key=[key]&token=[URL][top][/URL]][/text]</br>
		[Showif [JWT_DecryptIt string=[URL][psignature][/URL]]=[sig]]
			[text]result=T[/text]
		[/Showif]
	[/Showif]
	[RETURN][result][/RETURN]
	[!][result][/!]
[/Function]

[Function name=JWT_AuthenticateCookie]
	[text]res=F[/text]
	[Showif [JWT_VerifyToken token=[URL][GETCOOKIE name=[cookie]][/URL]&key=[key]]=T]
		[text]res=T[/text]
	[/Showif]
	[RETURN][res][/RETURN]
[/Function]
