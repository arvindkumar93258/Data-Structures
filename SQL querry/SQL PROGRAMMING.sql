PRINT 'HELLO'
PRINT 100 
GO



PRINT 'HELLO'+100
GO

PRINT 'HELLO '+CONVERT(VARCHAR, 100)
PRINT 'HELLO '+CAST(100 AS VARCHAR)

GO

---PRINT TODAYS DATE-----
PRINT CONVERT(VARCHAR,GETDATE())
GO


----------VARIABLE AND ASSIGNMENT-------

DECLARE @NAME VARCHAR(100)
SET @NAME='ARVIND'
PRINT 'HELLO ' + @NAME
GO


--TAKE NAME FROM TABLE
DECLARE @EMPNAME VARCHAR(100)
SELECT @EMPNAME=ENAME FROM EMP WHERE SAL=5000
GO
PRINT 'HELLO ' +@EMPNAME

---TAKE THE NUMBER FROM USER AND CHECK ODD EVEN-----

DECLARE @NUM INT
SET @NUM=2
IF @NUM%2=0
BEGIN
	PRINT 'EVEN'
	END
ELSE
BEGIN
	PRINT 'ODD'
END
GO


DECLARE @ITR INT=1
WHILE @ITR<5
BEGIN
	PRINT @ITR
	SET @ITR=@ITR+1
END
GO

-------ERROR HANDLING IN SQL=-------

BEGIN TRY
	SELECT 1/0;
END TRY
BEGIN CATCH
	PRINT 'ERROR'

	SELECT
		ERROR_NUMBER() AS ErrorNumber,
		error_severity() as errorseverity,
		error_state() as errorstate,
		error_procedure() as errorprocedure,
		error_line() AS ERRORLINE,
		ERROR_MESSAGE() AS ERRORMESSAGE;
		----LIKE C# ERROR THROWING
		--RAISEERROR(ERROR_MESSAGE, ERROR_SEVERITY, STATE)
		RAISERROR('NUMBER CAN NOT BE DIVIDE BY ZERO',16,1) 
		-- THROW 50001, 'NUMBER CAN NOT BE DIVIDE BY ZERO',0
END CATCH
GO


---STORE PROCEDURE
--MAY OR MAY NOT RETURN VALUE
-- CAN PERFORM DML OPERATION
--


CREATE PROCEDURE ODDEVENCHECK(@NUMBER INT) AS
BEGIN
	IF @NUMBER % 2 = 0
	BEGIN
		PRINT CAST(@NUMBER AS VARCHAR) + ' IS EVEN'
	END
	ELSE
	BEGIN
		PRINT CAST(@NUMBER AS VARCHAR) + ' IS ODD'
	END
END

EXEC ODDEVENCHECK 1000

EXEC ODDEVENCHECK 3

--- WRITE A PROCEDURE WHICH DISPLAYS ALL EMPLOYEE DATA FROM EMP TABLE
ALTER PROCEDURE DISPLAY_EMPDETAILS (@E_ID int) AS
BEGIN
DECLARE @NAME1 VARCHAR(20)
	DECLARE @JOB1 VARCHAR(20)
	DECLARE @DEPT1 INT
	DECLARE @COUNT INT
	SELECT @NAME1= ENAME, @JOB1=JOB, @DEPT1=DEPTNO FROM EMP WHERE EMPNO=@E_ID
	SET @COUNT  =@@ROWCOUNT
	IF @COUNT =0
	BEGIN
		RAISERROR('EMPLOYEE NOT FOUND',16,1)
	END
	ELSE
		PRINT @NAME1 + ' IS WORKING AS ' + @JOB1+ ' IN DEPARTEMENT NUMBER ' + CAST(@DEPT1 AS VARCHAR)
END

EXEC DISPLAY_EMPDETAILS 7370

/*
--TAKE MGRNO AS PARAMETER
--PRINT MESSAGE AS BELOW

TOTAL EMPLOYEE WORKING UNDER _____MGRNAME__________ = 4

IF NOT FOUND PRINT HE IS NOT A MANAGER
*/
ALTER PROCEDURE UNDERWORKINGSTAFF(@MGRNO INT) AS
BEGIN
	DECLARE @COUNT INT, @NAME VARCHAR, @ROW_EFFECTED INT
	SELECT @NAME=ENAME FROM EMP WHERE EMPNO=@MGRNO
	SELECT @COUNT=COUNT(EMPNO) FROM EMP WHERE EMPNO=@MGRNO GROUP BY MGR
	SET @ROW_EFFECTED= @@ROWCOUNT
	IF @ROW_EFFECTED=0
		RAISERROR('HE IS NOT A MANAGER',16,1)
	ELSE
		PRINT 'TOTAL EMPLOYEE WORKING UNDER '+@NAME+' = '+CAST(VARCHAR AS @COUNT)

END

EXEC UNDERWORKINGSTAFF 7698




ALTER PROC MANAGER_EMP_COUNT (@ENO INT) AS
BEGIN
	DECLARE @COUNT INT,  @EMPNAME VARCHAR(20), @EMPCOUNT INT,@MGRNAME VARCHAR(20), @ROWCOUNT INT
	SELECT @MGRNAME=ENAME FROM EMP WHERE EMPNO=@ENO
	SET @ROWCOUNT=@@ROWCOUNT
	IF @ROWCOUNT > 0
	BEGIN 
		SELECT @EMPCOUNT=COUNT(EMPNO) FROM EMP WHERE MGR=@ENO
		IF @EMPCOUNT = 0
			PRINT 'NO EMPLOYEE IS WORKING UNDER - '+@MGRNAME
		ELSE 
		BEGIN
			PRINT 'TOTAL EMPLOYEE REPORTING TO '+@MGRNAME + ' IS '+CAST(@EMPCOUNT AS VARCHAR)

			DECLARE MGR_CURSOR CURSOR FOR SELECT E.ENAME FROM EMP AS E JOIN EMP M ON E.MGR=M.EMPNO WHERE M.EMPNO=@ENO
			FETCH NEXT FROM MGR_CURSOR INTO @EMPNAME

			WHILE @@FETCH_STATUS =0
				BEGIN
					PRINT 'EMPLOYEE NAME '+@EMPNAME
					FETCH NEXT FROM MGR_CURSOR
				END
				CLOSE MGR_CURSOR
				DEALLOCATE MGR_CURSOR
		END
	END
	ELSE
		RAISERROR('NOT ANY MANAGER FOUNT',16,1)
END

CREATE PROC OUTPARADEMO (@DNO INT, @MINSAL NUMERIC(10,2) OUT, @MAXSAL NUMERIC(10,2) OUT, @COUNT INT OUT) AS
BEGIN
	SELECT @MINSAL=MIN(SAL), @MAXSAL=MAX(SAL), @COUNT=COUNT(EMPNO) FROM EMP WHERE DEPTNO=@DNO
END


DECLARE @MINSAL NUMERIC(10,2) , @MAXSAL NUMERIC(10,2), @COUNT INT
EXEC OUTPARADEMO 10, @MINSAL OUT, @MAXSAL OUT, @COUNT OUT
PRINT 'MINSAL = '+CAST(@MINSAL AS VARCHAR) +CHAR(13)+' MAXSAL = '+CAST(@MAXSAL AS VARCHAR)+CHAR(13) 
+' COUNT = '+CAST(@COUNT AS VARCHAR)


--SAME AS ABOVE, INSTEAD OF USING DEPTNO USE DEPTNAME

CREATE PROC OUTPARADEMO2 (@DPTNAME VARCHAR, @MINSAL NUMERIC(10,2) OUT, @MAXSAL NUMERIC(10,2) OUT, @COUNT INT OUT) AS
BEGIN
	SELECT @MINSAL=MIN(SAL), @MAXSAL=MAX(SAL), @COUNT=COUNT(EMPNO) FROM EMP WHERE DEPTNO IN (SELECT DEPTNO FROM DEPT WHERE DNAME=@DPTNAME)
END

DECLARE @MINSAL2 NUMERIC(10,2) , @MAXSAL2 NUMERIC(10,2), @COUNT2 INT
EXEC OUTPARADEMO SALES, @MINSAL OUT, @MAXSAL OUT, @COUNT OUT
PRINT 'MINSAL = '+CAST(@MINSAL AS VARCHAR) +CHAR(13)+' MAXSAL = '+CAST(@MAXSAL AS VARCHAR)+CHAR(13) 
+' COUNT = '+CAST(@COUNT AS VARCHAR)



------------INSERT PROCEDURE----------
--WRITE A PROCEDURE WHICH TAKES EMPNO, ENAME, DEPTNO AS PARAMETER 
--INSERT VALUE IN EMP TABLE, IF INSERTED SUCCESSFULLY THEN PASS MESSAGE OTHERWISE NOT SUCCESS
CREATE PROC INSERT_REC(@EMPNO VARCHAR(20), @ENAME VARCHAR(20), @DEPTNO INT) AS
BEGIN
	DECLARE @CHECK_S INT
	INSERT INTO EMP(EMPNO, ENAME, DEPTNO) VALUES(@EMPNO, @ENAME, @DEPTNO)
	SET @CHECK_S=@@ROWCOUNT
	IF @CHECK_S = 0
		RAISERROR('INSERTION FAIL ',16,1)
	ELSE
		PRINT 'INSERTION SUCCESSFULL '
END




--DELETE PROCEDURE
--TAKE EMPNO FROM USER
--IF FOUND DELETE THE RECORD, IF DELETED THEN SUCCESSFULL MESSAGE OUT OTHERWISE NOT SUCCESSFULL
CREATE PROC DELETE_FROM(@EMPNAME VARCHAR(20)) AS 
BEGIN
	DECLARE @COUNT INT
	DELETE FROM EMP WHERE ENAME=@EMPNAME
	SET @COUNT=@@ROWCOUNT
	IF @COUNT = 0
		RAISERROR('DELETE NOT FOUND',16,1)
	ELSE
		PRINT 'ROW DELETED SUCCESSFULLY'
END


SELECT * FROM EMP FOR XML AUTO
-- SELECT * FROM EMP FOR XML RAW   //
-- SELECT * FROM EMP FOR XML PATH

 DECLARE @FileXML XML = '
 <EMPLOYEELIST>
   <EMPLOYEE>
     <EMPNO>1</EMPNO>	 
     <EMPNAME>BHAVANA</EMPNAME>     
     <SALARY>4000</SALARY>
   </EMPLOYEE>
   <EMPLOYEE>
     <EMPNO>2</EMPNO>
     <EMPNAME>VISHAL</EMPNAME>     
     <SALARY>3000</SALARY>
   </EMPLOYEE>  
 </EMPLOYEELIST>'







CREATE PROCEDURE parseXMLTOTABLE @inputXML XML AS
BEGIN 
	INSERT INTO EMP(EMPNO, ENAME, SAL) 
		SELECT
		RESULTS.EMPLOYEELIST.VALUE('EMPNO[1]','INT') AS EMPNO
		RESULTS.EMPLOYEELIST.VALUE('EMPNAME[1]','NVCHAR(20)') AS EMPNAME
		RESULTS.EMPLOYEELIST.VALUE('EMPSAM[1]','NUMERIC(10,2)') AS SALARY
		FROM @inputXML.nodes(EMPLOYEELIST/EMPLOYEE) RESULTS (EMPLOYEELIST)

		SELECT * FROM EMP

EN



--FUNCTION
--ALWAYS RETURN A VALUE
--CAN'T PERFORM DML OPERATION OR MAY BE BUT WE DON'T USE IT















