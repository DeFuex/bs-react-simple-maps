let fromOption = Js.Nullable.fromOption;

module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external composableMapClass : ReasonReact.reactClass = "ComposableMap";
  [@bs.deriving abstract]
  type projectionConfigT = {
    scale: int,
    rotation: array(int),
  };
  [@bs.deriving abstract]
  type jsProps = {
    width: Js.nullable(int),
    height: Js.nullable(int),
    projection: Js.nullable(string),
    projectionConfig: projectionConfigT,
  };
  let make =
      (~width=?, ~height=?, ~projection=?, ~projectionConfig, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMapClass,
      ~props=
        jsProps(
          ~width=fromOption(width),
          ~height=fromOption(height),
          ~projection=fromOption(projection),
          ~projectionConfig=projectionConfig,
        ),
      children,
    );
};

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external zoomableGroupClass : ReasonReact.reactClass = "ZoomableGroup";
  [@bs.deriving abstract]
  type jsProps = {
    zoom: Js.nullable(int),
    center: Js.nullable(array(int)),
    disablePanning: Js.nullable(bool),
    /* style: Js.nullable(), */
    /* onMoveStart: Js.nullable(() => unit), */
  };
  let make = (~zoom=?, ~center=?, ~disablePanning=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroupClass,
      ~props=
        jsProps(
          ~zoom=fromOption(zoom),
          ~center=fromOption(center),
          ~disablePanning=fromOption(disablePanning),
        ),
      children,
    );
};

module Geography = {
  type projectionT;
  [@bs.deriving abstract]
  type geographyT = {id: string};
  [@bs.module "react-simple-maps"]
  external geographyClass : ReasonReact.reactClass = "Geography";
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    cacheId: Js.nullable(int),
    precision: Js.nullable(int),
    round: Js.nullable(bool),
    geography: Js.nullable(geographyT),
    tabable: Js.nullable(bool),
    projection: projectionT,
    style: Js.nullable(styleT),
  };
  let make =
      (
        ~cacheId=?,
        ~precision=?,
        ~round=?,
        ~geography=?,
        ~projection,
        ~tabable=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyClass,
      ~props=
        jsProps(
          ~cacheId=fromOption(cacheId),
          ~precision=fromOption(precision),
          ~round=fromOption(round),
          ~geography=fromOption(geography),
          ~projection,
          ~tabable=fromOption(tabable),
          ~style=fromOption(style),
        ),
      children,
    );
};

module Geographies = {
  [@bs.module "react-simple-maps"]
  external geographiesClass : ReasonReact.reactClass = "Geographies";
  [@bs.deriving abstract]
  type jsProps = {
    disableOptimization: Js.nullable(bool),
    geography: Js.nullable(string) /* or object, or array */
  };
  let make = (~disableOptimization=?, ~geography=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographiesClass,
      ~props=
        jsProps(
          ~disableOptimization=fromOption(disableOptimization),
          ~geography=fromOption(geography),
        ),
      children,
    );
};

module Markers = {
  [@bs.module "react-simple-maps"]
  external markersClass : ReasonReact.reactClass = "Markers";

  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markersClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

module Marker = {
  [@bs.module "react-simple-maps"]
  external markerClass : ReasonReact.reactClass = "Marker";
  [@bs.deriving abstract]
  type markerT = {
    coordinates: array(float),
  };
  [@bs.deriving abstract]
  type jsProps = {
    marker: markerT,
  };
  let make = (~marker, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markerClass,
      ~props=
        jsProps(
          ~marker=marker,
        ),
      children,
    );
};

module Annotations = {
  [@bs.module "react-simple-maps"]
  external annotationsClass : ReasonReact.reactClass = "Annotations";

  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=annotationsClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

module Annotation = {
  [@bs.module "react-simple-maps"]
  external annotationClass : ReasonReact.reactClass = "Annotation";
  [@bs.deriving abstract]
  type styleT;
  [@bs.deriving abstract]
  type jsProps = {
    subject: Js.nullable(array(float)),
    dx: Js.nullable(int),
    dy: Js.nullable(int),
    zoom: Js.nullable(int),
    stroke: Js.nullable(string),
    strokeWidth: Js.nullable(int),
    style: Js.nullable(styleT),
    markerEnd: Js.nullable(string),
    curve: Js.nullable(int),
  };
  let make =
      (
        ~subject=?,
        ~dx=?,
        ~dy=?,
        ~zoom=?,
        ~stroke=?,
        ~strokeWidth=?,
        ~style=?,
        ~markerEnd=?,
        ~curve=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=annotationClass,
      ~props=
        jsProps(
          ~subject=fromOption(subject),
          ~dx=fromOption(dx),
          ~dy=fromOption(dy),
          ~zoom=fromOption(zoom),
          ~stroke=fromOption(stroke),
          ~strokeWidth=fromOption(strokeWidth),
          ~style=fromOption(style),
          ~markerEnd=fromOption(markerEnd),
          ~curve=fromOption(curve),
        ),
      children,
    );
};

module Graticule = {
  [@bs.module "react-simple-maps"]
  external graticuleClass : ReasonReact.reactClass = "Graticule";
  [@bs.deriving abstract]
  type styleT = {
    pointerEvents: string,
  };
  [@bs.deriving abstract]
  type jsProps = {
    step: Js.nullable(array(int)),
    round: Js.nullable(bool),
    precision: Js.nullable(float),
    outline: Js.nullable(bool),
    stroke: Js.nullable(string),
    fill: Js.nullable(string),
    style: Js.nullable(styleT),
    disableOptimization: Js.nullable(bool),
    globe: Js.nullable(bool),
  };
  let make =
      (
        ~step=?,
        ~round=?,
        ~precision=?,
        ~outline=?,
        ~stroke=?,
        ~fill=?,
        ~style=?,
        ~disableOptimization=?,
        ~globe=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=graticuleClass,
      ~props=
        jsProps(
          ~step=fromOption(step),
          ~round=fromOption(round),
          ~precision=fromOption(precision),
          ~outline=fromOption(outline),
          ~stroke=fromOption(stroke),
          ~fill=fromOption(fill),
          ~style=fromOption(style),
          ~disableOptimization=fromOption(disableOptimization),
          ~globe=fromOption(globe),
        ),
      children,
    );
};

module Lines = {
  [@bs.module "react-simple-maps"]
  external linesClass : ReasonReact.reactClass = "Lines";

  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linesClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

module Line = {
  [@bs.module "react-simple-maps"]
  external lineClass : ReasonReact.reactClass = "Line";
  [@bs.deriving abstract]
  type coordinatesT = {
    start: array(float),
    [@bs.as "end"]
    _end: array(float),
  };
  [@bs.deriving abstract]
  type curveT = {
    forceUp: string,
    forceDown: string,
  };
  [@bs.deriving abstract]
  type lineT = {
    coordinates: coordinatesT,
  };
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    line: Js.nullable(lineT),
    tabable: Js.nullable(bool),
    style: Js.nullable(styleT),
    preserveMarkerAspect: Js.nullable(bool),
    buildPath: Js.nullable((array(float), array(float), lineT) => curveT),
  };
  let make =
      (
        ~line=?,
        ~tabable=?,
        ~style=?,
        ~preserveMarkerAspect=?,
        ~buildPath=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=lineClass,
      ~props=
        jsProps(
          ~line=fromOption(line),
          ~tabable=fromOption(tabable),
          ~style=fromOption(style),
          ~preserveMarkerAspect=fromOption(preserveMarkerAspect),
          ~buildPath=fromOption(buildPath),
        ),
      children,
    );
};