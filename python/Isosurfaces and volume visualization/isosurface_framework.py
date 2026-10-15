# ################################################################
# Import Packages
# ################################################################
from vtkmodules.vtkIOXML import vtkXMLImageDataReader
import vtkmodules.vtkRenderingOpenGL2
    
from vtkmodules.vtkFiltersModeling import vtkOutlineFilter
from vtkmodules.vtkCommonDataModel import vtkPlane, vtkPlaneCollection
from vtkmodules.vtkFiltersCore import (
    vtkContourFilter
)
from vtkmodules.vtkInteractionStyle import vtkInteractorStyleTrackballCamera
from vtkmodules.vtkRenderingCore import (
    vtkActor,
    vtkPolyDataMapper,
    vtkRenderWindow,
    vtkRenderWindowInteractor,
    vtkProperty,
    vtkRenderer,
)
from vtkmodules.vtkCommonColor import vtkNamedColors
from vtkmodules.vtkCommonCore import vtkCommand


import sys
import getopt

def ReadInputFile(InputFilename):
    reader = vtkXMLImageDataReader()
    reader.SetFileName(InputFilename)
    reader.Update()
    return reader.GetOutput()
    
        
def CreateVisualizationFromListOfActors(ListOfActors, RotateCamera):
    #create a renderer
    render = vtkRenderer()
    render.SetUseDepthPeeling(True)
    render.SetMaximumNumberOfPeels(100)
    render.SetOcclusionRatio(0)
    #Add the Actors to Renderer
    for i in range(0,len(ListOfActors)):
        render.AddActor(ListOfActors[i])
    #Create Render Window
    window = vtkRenderWindow()
    window.SetAlphaBitPlanes(1)
    window.SetMultiSamples(0) 
    window.AddRenderer(render)
    #Create Interactor
    interactor = vtkRenderWindowInteractor()
    interactor.SetRenderWindow(window)
    interactor.SetInteractorStyle(vtkInteractorStyleTrackballCamera())
    # interactor.Initialize()
    camera = render.GetActiveCamera()
    camera.SetPosition(142, -813, 147)
    camera.SetFocalPoint(114, 141, 135)
    camera.SetViewUp(0, 0, -1)
    camera.SetClippingRange(0.1, 2000)
    # define callback function for rotation
    def rotate_camera(caller, event):
        camera.Azimuth(3)
        # print(camera.GetPosition(), camera.GetFocalPoint(), camera.GetViewUp())
        window.Render()

    # Setup a timer callback for rotating the camera
    if RotateCamera:
        interactor.AddObserver(vtkCommand.TimerEvent, rotate_camera)
        interactor.Initialize()
        interactor.CreateRepeatingTimer(10)
    interactor.Start()

def task1(InputData):
    # create a BoundingBox using 
    # vtkOutlineFilter 
    # vtkPolyDataMapper
    # vtkActor 
    outline_filter = vtkOutlineFilter()
    outline_filter.SetInputData(InputData)
    outline_filter.Update()
    
    outline_mapper = vtkPolyDataMapper()
    outline_mapper.SetInputConnection(outline_filter.GetOutputPort())
    
    outActor = vtkActor()
    outActor.SetMapper(outline_mapper)
    outActor.GetProperty().SetColor(vtkNamedColors().GetColor3d('LightGreen'))
    #return the actor
    return outActor
  
def task2(InputData):
    #create a contour using contourFilter
    bones_filter = vtkContourFilter()
    bones_filter.SetInputData(InputData)
    bones_filter.SetValue(1, 75.0)
    bones_filter.Update()
    
    bones_mapper = vtkPolyDataMapper()
    bones_mapper.SetInputConnection(bones_filter.GetOutputPort())
    bones_mapper.ScalarVisibilityOff()
    
    bonesActor = vtkActor()
    bonesActor.SetMapper(bones_mapper)
    bonesActor.GetProperty().SetColor(vtkNamedColors().GetColor3d('Yellow'))
    bonesActor.GetProperty().SetOpacity(1)
    #return the actor
    return bonesActor
    
def task3(InputData):
    #create a contour using contourFilter
    skin_filter = vtkContourFilter()
    skin_filter.SetInputData(InputData)
    skin_filter.SetValue(0, 30.0)
    skin_filter.Update()
    
    skin_mapper = vtkPolyDataMapper()
    skin_mapper.SetInputConnection(skin_filter.GetOutputPort())
    skin_mapper.ScalarVisibilityOff()
    
    clip_plane = vtkPlane()
    clip_plane.SetOrigin(0, 100, 0)
    clip_plane.SetNormal(0, 1, 0)
    skin_mapper.AddClippingPlane(clip_plane)
    
    skinnActor = vtkActor()
    skinnActor.SetMapper(skin_mapper)
    skinnActor.GetProperty().SetColor(vtkNamedColors().GetColor3d('Red'))
    skinnActor.GetProperty().SetOpacity(0.5)
    #return the actor
    return skinnActor



#Defining the Main Function 
def main(argv):
    # define input variables
    helpstr = """IntroVtkPython.py -i <InputFilename> [optional -b <ShowBoundingBox>]"""
    # parse command line
    InputFilename = None
    ShowBBoxInStr = None
    RotateCameraInStr = None
    ShowBBox = False
    RotateCamera = False
    try:
        opts, args = getopt.getopt(argv,"i:b:a:")
    except getopt.GetoptError:
        print (helpstr)
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print (helpstr)
            sys.exit()
        elif opt == "-i":
            InputFilename = arg
        elif opt == "-b":
            ShowBBoxInStr = arg
        elif opt == "-a":
            RotateCameraInStr = arg

    if InputFilename==None:
        print (helpstr)
        sys.exit(2)
    if ShowBBoxInStr=="true":
        ShowBBox = True
    if RotateCameraInStr=="true":
        RotateCamera = True

    # ######################################
    # Finished Parsing Agruments
    # ######################################

    # reading the file
    data = ReadInputFile(InputFilename)
    #adding the actors to A List Of Actors
    ListOfActors = []
    # disable the visibility of the BboxActor when
    # the boundingbox should not be shown
    if ShowBBox:
        BboxActor    = task1(data)
        ListOfActors.append(BboxActor)
    
    BonesActor   = task2(data)
    ListOfActors.append(BonesActor)
    
    SkinActor    = task3(data)
    ListOfActors.append(SkinActor)
    
    # create visualization and interaction 
    CreateVisualizationFromListOfActors(ListOfActors, RotateCamera)
    
#Entry point
if __name__ == "__main__":
    main(sys.argv[1:])