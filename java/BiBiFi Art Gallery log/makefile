JFLAGS = -g
JC = javac
JAR = jar

CLASS_FILES = l_append/LogAppend.class l_read/LogRead.class
PICOCILI_JAR = libraries/picocli-4.7.5.jar
JSON_JAR = libraries/gson-2.8.2.jar

# SRCPATH = libraries


Default: create_bin


%.class: %.java
	$(JC) $(JFLAGS) -cp "$(PICOCILI_JAR):$(JSON_JAR)" $<

create_bin: logappend.jar logread.jar

logappend.jar: l_append/LogAppend.class
	$(JAR) -cvmf MANIFEST_LA.MF $@ -C . l_append/
	cat stub.sh $@ > logappend && chmod +x logappend

logread.jar: l_read/LogRead.class
	$(JAR) -cvmf MANIFEST_LR.MF $@ -C . l_read/
	cat stub.sh $@ > logread && chmod +x logread


clean:
	$(RM) l_read/*.class l_append/*.class log*
