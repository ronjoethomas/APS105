##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab5
ConfigurationName      :=Debug
WorkspacePath          :=/u/b/thoma540/Documents/Lab5
ProjectPath            :=/u/b/thoma540/Documents/Lab5/Lab5
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ron Joe  Thomas
Date                   :=15/02/19
CodeLitePath           :=/u/b/thoma540/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Lab5.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lm
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -std=c99 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Lab5Part3.c$(ObjectSuffix) $(IntermediateDirectory)/Lab5Part2.c$(ObjectSuffix) $(IntermediateDirectory)/Lab5Part1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Lab5Part3.c$(ObjectSuffix): Lab5Part3.c $(IntermediateDirectory)/Lab5Part3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/u/b/thoma540/Documents/Lab5/Lab5/Lab5Part3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab5Part3.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab5Part3.c$(DependSuffix): Lab5Part3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab5Part3.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab5Part3.c$(DependSuffix) -MM Lab5Part3.c

$(IntermediateDirectory)/Lab5Part3.c$(PreprocessSuffix): Lab5Part3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab5Part3.c$(PreprocessSuffix) Lab5Part3.c

$(IntermediateDirectory)/Lab5Part2.c$(ObjectSuffix): Lab5Part2.c $(IntermediateDirectory)/Lab5Part2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/u/b/thoma540/Documents/Lab5/Lab5/Lab5Part2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab5Part2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab5Part2.c$(DependSuffix): Lab5Part2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab5Part2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab5Part2.c$(DependSuffix) -MM Lab5Part2.c

$(IntermediateDirectory)/Lab5Part2.c$(PreprocessSuffix): Lab5Part2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab5Part2.c$(PreprocessSuffix) Lab5Part2.c

$(IntermediateDirectory)/Lab5Part1.c$(ObjectSuffix): Lab5Part1.c $(IntermediateDirectory)/Lab5Part1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/u/b/thoma540/Documents/Lab5/Lab5/Lab5Part1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab5Part1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lab5Part1.c$(DependSuffix): Lab5Part1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Lab5Part1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/Lab5Part1.c$(DependSuffix) -MM Lab5Part1.c

$(IntermediateDirectory)/Lab5Part1.c$(PreprocessSuffix): Lab5Part1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lab5Part1.c$(PreprocessSuffix) Lab5Part1.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


