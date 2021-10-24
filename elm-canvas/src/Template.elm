module Template exposing (main)

import Browser
import Browser.Events exposing (onAnimationFrameDelta)
import Canvas exposing (rect, shapes, clear)
import Canvas.Settings exposing (fill)
import Canvas.Settings.Advanced exposing (rotate, transform, translate)
import Color
import Html exposing (Html, div)
import Html.Attributes exposing (style)

type alias Model = 
    { count : Float }

type Msg
    = Frame Float

width = 
    400

height =
    400

centerX = 
    width / 2

centerY =
    height / 2

main : Program () Model Msg
main = 
    Browser.element
        { init = init
        , view = view
        , update = update
        , subscriptions = \_ -> onAnimationFrameDelta Frame
        }

init : () -> ( Model, Cmd Msg )
init () = 
    ( { count = 0 }, Cmd.none )

update : Msg -> Model -> ( Model, Cmd Msg )
update msg model =
    case msg of
        Frame _ -> 
            ( { model | count = model.count + 1 }, Cmd.none )

view : Model -> Html Msg
view model =
    div
        [ style "display" "flex"
        , style "justify-content" "center"
        , style "align-items" "center"
        ]
        [ Canvas.toHtml
            ( width, height )
            [ style "border" "10px solid rgba(0,0,0,0.1)" ]
            [ clear ( 0, 0 ) width height
            , render model.count
            ]
        ]

render : Float -> Canvas.Renderable
render count =
    let 
        size =
            width / 3
        
        x = 
            -(size / 2)

        y = 
            -(size / 2)

        rotation =
            degrees (count * 3)

        hue =
            toFloat (count / 4 |> floor |> modBy 100) / 100
    in
    shapes
        [ transform 
            [ translate centerX centerY 
            , rotate rotation
            ]
        , fill (Color.hsl hue 0.3 0.7)
        ]
        [ rect ( x, y ) size size
        ]