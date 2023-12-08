object ColorSorter: TColorSorter
  Left = 0
  Top = 0
  Width = 772
  Height = 689
  HorzScrollBar.Smooth = True
  HorzScrollBar.Tracking = True
  VertScrollBar.Smooth = True
  VertScrollBar.Tracking = True
  AutoScroll = True
  Caption = 'Color Sorter'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 8
    Top = 9
    Width = 265
    Height = 193
    Caption = 'Settings'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 23
      Width = 42
      Height = 23
      Caption = 'RED'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 52
      Width = 70
      Height = 23
      Caption = 'GREEN'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 81
      Width = 54
      Height = 23
      Caption = 'BLUE'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object HeightFractionLabel: TLabel
      Left = 13
      Top = 124
      Width = 93
      Height = 19
      Caption = 'Height Fraction'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = -144
      Top = 405
      Width = 34
      Height = 15
      Caption = 'Label5'
    end
    object WidthFractionLabel: TLabel
      Left = 16
      Top = 149
      Width = 90
      Height = 19
      Caption = 'Width Fraction'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object WidthFraction: TEdit
      Left = 122
      Top = 120
      Width = 39
      Height = 23
      NumbersOnly = True
      TabOrder = 0
      Text = '1'
    end
    object HeightFraction: TEdit
      Left = 122
      Top = 149
      Width = 39
      Height = 23
      NumbersOnly = True
      TabOrder = 1
      Text = '1'
    end
  end
  object GetFiles: TButton
    Left = 288
    Top = 28
    Width = 113
    Height = 25
    Caption = 'Click to Get Files'
    TabOrder = 1
    OnClick = GetFilesClick
  end
  object BEGIN: TButton
    Left = 288
    Top = 121
    Width = 113
    Height = 25
    Caption = 'BEGIN SORTING!'
    TabOrder = 2
    OnClick = BEGINClick
  end
  object TheConsole: TRichEdit
    Left = 8
    Top = 216
    Width = 737
    Height = 427
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    HideScrollBars = False
    Lines.Strings = (
      'Welcome to the Afsharid Color Sorting Project!'
      'To begin:'
      'Step 1) Select the color you want to sort your pictures by.'
      
        'Step 2) Click "Click to Get Files" so the program can see the fi' +
        'les in the directory.'
      
        'Step 3) If you'#39're sorting JPG or PNG files, click to convert the' +
        'm (originals wont be deleted). '
      'Otherwise ignore this step.'
      'Step 4) Click "BEGIN SORTING!" to sort your files.'
      'The results will be in an output folder.')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object Red: TEdit
    Left = 130
    Top = 29
    Width = 65
    Height = 23
    NumbersOnly = True
    TabOrder = 4
    Text = '0'
  end
  object Green: TEdit
    Left = 130
    Top = 58
    Width = 65
    Height = 23
    NumbersOnly = True
    TabOrder = 5
    Text = '0'
  end
  object Blue: TEdit
    Left = 130
    Top = 87
    Width = 65
    Height = 23
    NumbersOnly = True
    TabOrder = 6
    Text = '0'
  end
  object UpDown2: TUpDown
    Left = 195
    Top = 29
    Width = 16
    Height = 23
    Associate = Red
    Max = 255
    TabOrder = 7
  end
  object UpDown3: TUpDown
    Left = 195
    Top = 58
    Width = 16
    Height = 23
    Associate = Green
    Max = 255
    TabOrder = 8
  end
  object UpDown4: TUpDown
    Left = 195
    Top = 87
    Width = 16
    Height = 23
    Associate = Blue
    Max = 255
    TabOrder = 9
  end
  object ConvertJPG: TButton
    Left = 304
    Top = 59
    Width = 75
    Height = 25
    Caption = 'Convert JPG'
    TabOrder = 10
    OnClick = ConvertJPGClick
  end
  object ConvertPNG: TButton
    Left = 304
    Top = 90
    Width = 75
    Height = 25
    Caption = 'Convert PNG'
    TabOrder = 11
    OnClick = ConvertPNGClick
  end
  object ListOfColors: TListBox
    Left = 416
    Top = 18
    Width = 336
    Height = 184
    ImeName = 'ListOfColors'
    ItemHeight = 15
    Items.Strings = (
      'Alice Blue'#9'(240,248,255)'
      'Antique White'#9'(250,235,215)'
      'Aqua'#9'(0,255,255)'
      'Aqua Marine'#9'(127,255,212)'
      'Azure'#9'(240,255,255)'
      'Beige'#9'(245,245,220)'
      'Bisque'#9'(255,228,196)'
      'Black'#9'(0,0,0)'
      'Blanched Almond'#9'(255,235,205)'
      'Blue'#9'(0,0,255)'
      'Blue Violet'#9'(138,43,226)'
      'Brown'#9'(165,42,42)'
      'Burly Wood'#9'(222,184,135)'
      'Cadet Blue'#9'(95,158,160)'
      'Chartreuse'#9'(127,255,0)'
      'Chocolate'#9'(210,105,30)'
      'Coral'#9'(255,127,80)'
      'Corn Flower Blue'#9'(100,149,237)'
      'Corn Silk'#9'(255,248,220)'
      'Crimson'#9'(220,20,60)'
      'Cyan'#9'(0,255,255)'
      'Dark Blue'#9'(0,0,139)'
      'Dark Cyan'#9'(0,139,139)'
      'Dark Golden Rod'#9'(184,134,11)'
      'Dark Gray / Dark Grey'#9'(169,169,169)'
      'Dark Green'#9'(0,100,0)'
      'Dark Khaki'#9'(189,183,107)'
      'Dark Magenta'#9'(139,0,139)'
      'Dark Olive Green'#9'(85,107,47)'
      'Dark Orange'#9'(255,140,0)'
      'Dark Orchid'#9'(153,50,204)'
      'Dark Red'#9'(139,0,0)'
      'Dark Salmon'#9'(233,150,122)'
      'Dark Sea Green'#9'(143,188,143)'
      'Dark Slate Blue'#9'(72,61,139)'
      'Dark Slate Gray'#9'(47,79,79)'
      'Dark Turquoise'#9'(0,206,209)'
      'Dark Violet'#9'(148,0,211)'
      'Deep Pink'#9'(255,20,147)'
      'Deep Sky Blue'#9'(0,191,255)'
      'Dim Gray / Dim Grey'#9'(105,105,105)'
      'Dodger Blue'#9'(30,144,255)'
      'Firebrick'#9'(178,34,34)'
      'Floral White'#9'(255,250,240)'
      'Forest Green'#9'(34,139,34)'
      'Gainsboro'#9'(220,220,220)'
      'Ghost White'#9'(248,248,255)'
      'Gold'#9'(255,215,0)'
      'Golden Rod'#9'(218,165,32)'
      'Gray / Grey'#9'(128,128,128)'
      'Green'#9'(0,128,0)'
      'Green Yellow'#9'(173,255,47)'
      'Honeydew'#9'(240,255,240)'
      'Hot Pink'#9'(255,105,180)'
      'Indian Red'#9'(205,92,92)'
      'Indigo'#9'(75,0,130)'
      'Iranian Green (35,159,63)'
      'Ivory'#9'(255,255,240)'
      'Khaki'#9'(240,230,140)'
      'Lavender'#9'(230,230,250)'
      'Lavender Blush'#9'(255,240,245)'
      'Lawn Green'#9'(124,252,0)'
      'Lemon Chiffon'#9'(255,250,205)'
      'Light Blue'#9'(173,216,230)'
      'Light Coral'#9'(240,128,128)'
      'Light Cyan'#9'(224,255,255)'
      'Light Golden Rod Yellow'#9'(250,250,210)'
      'Light Gray / Light Grey'#9'(211,211,211)'
      'Light Green'#9'(144,238,144)'
      'Light Pink'#9'(255,182,193)'
      'Light Salmon'#9'(255,160,122)'
      'Light Sea Green'#9'(32,178,170)'
      'Light Sky Blue'#9'(135,206,250)'
      'Light Slate Gray'#9'(119,136,153)'
      'Light Steel Blue'#9'(176,196,222)'
      'Light Yellow'#9'(255,255,224)'
      'Lime'#9'(0,255,0)'
      'Lime Green'#9'(50,205,50)'
      'Linen'#9'(250,240,230)'
      'Magenta'#160'/'#160'Fuchsia'#9'(255,0,255)'
      'Maroon'#9'(128,0,0)'
      'Medium Aqua Marine'#9'(102,205,170)'
      'Medium Blue'#9'(0,0,205)'
      'Medium Orchid'#9'(186,85,211)'
      'Medium Purple'#9'(147,112,219)'
      'Medium Sea Green'#9'(60,179,113)'
      'Medium Slate Blue'#9'(123,104,238)'
      'Medium Spring Green'#9'(0,250,154)'
      'Medium Turquoise'#9'(72,209,204)'
      'Medium Violet Red'#9'(199,21,133)'
      'Midnight Blue'#9'(25,25,112)'
      'Mint Cream'#9'(245,255,250)'
      'Misty Rose'#9'(255,228,225)'
      'Moccasin'#9'(255,228,181)'
      'Navajo White'#9'(255,222,173)'
      'Navy'#9'(0,0,128)'
      'Old Lace'#9'(253,245,230)'
      'Olive'#9'(128,128,0)'
      'Olive Drab'#9'(107,142,35)'
      'Orange'#9'(255,165,0)'
      'Orange Red'#9'(255,69,0)'
      'Orchid'#9'(218,112,214)'
      'Pale Golden Rod'#9'(238,232,170)'
      'Pale Green'#9'(152,251,152)'
      'Pale Turquoise'#9'(175,238,238)'
      'Pale Violet Red'#9'(219,112,147)'
      'Papaya Whip'#9'(255,239,213)'
      'Peach Puff'#9'(255,218,185)'
      'Peru'#9'(205,133,63)'
      'Pink'#9'(255,192,203)'
      'Plum'#9'(221,160,221)'
      'Powder Blue'#9'(176,224,230)'
      'Purple'#9'(128,0,128)'
      'Red'#9'(255,0,0)'
      'Rosy Brown'#9'(188,143,143)'
      'Royal Blue'#9'(65,105,225)'
      'Saddle Brown'#9'(139,69,19)'
      'Salmon'#9'(250,128,114)'
      'Sandy Brown'#9'(244,164,96)'
      'Sea Green'#9'(46,139,87)'
      'Sea Shell'#9'(255,245,238)'
      'Sienna'#9'(160,82,45)'
      'Silver'#9'(192,192,192)'
      'Sky Blue'#9'(135,206,235)'
      'Slate Blue'#9'(106,90,205)'
      'Slate Gray'#9'(112,128,144)'
      'Snow'#9'(255,250,250)'
      'Spring Green'#9'(0,255,127)'
      'Steel Blue'#9'(70,130,180)'
      'Tan'#9'(210,180,140)'
      'Teal'#9'(0,128,128)'
      'Thistle'#9'(216,191,216)'
      'Tomato'#9'(255,99,71)'
      'Turquoise'#9'(64,224,208)'
      'Violet'#9'(238,130,238)'
      'Wheat'#9'(245,222,179)'
      'White'#9'(255,255,255)'
      'White Smoke'#9'(245,245,245)'
      'Yellow'#9'(255,255,0)'
      'Yellow Green'#9'(154,205,50)'
      ''
      '')
    TabOrder = 12
    OnClick = ListOfColorsClick
  end
end
