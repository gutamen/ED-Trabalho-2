JFLAGS = -g
JFLAG = -cfvm
SIS = rm
JAR = -jar
JC = javac
JDK = jar
JVM= java 
FILE= execut.jar

.SUFFIXES: .java .class

run:
		$(JC) $/javaFila/*.java
		$(JDK) $(JFLAG) $(FILE) MANIFEST.MF $/javaFila/*.class
		$(JVM) $(JAR) $(FILE) >> resultado.txt

CLASSES = \
	javaFila/FilaFromLista.java \
    javaFila/Fila.java \
    javaFila/Lista.java \
    javaFila/dataStructLista.java 

MAIN = javaFila/FilaFromLista 

default: classes

classes: $(CLASSES:.java=.class)	

clean:
		$(RM) javaFila/*.class
		$(SIS) resultado.txt