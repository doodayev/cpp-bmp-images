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
      Left = 16
      Top = 120
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
      Top = 145
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
    object HeightFraction: TEdit
      Left = 122
      Top = 120
      Width = 39
      Height = 23
      NumbersOnly = True
      TabOrder = 0
      Text = '1'
    end
    object WidthFraction: TEdit
      Left = 122
      Top = 149
      Width = 39
      Height = 23
      NumbersOnly = True
      TabOrder = 1
      Text = '1'
    end
  end
  object Button1: TButton
    Left = 304
    Top = 28
    Width = 75
    Height = 25
    Caption = 'Click'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 304
    Top = 121
    Width = 75
    Height = 25
    Caption = 'BEGIN!'
    TabOrder = 2
    OnClick = Button2Click
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
      'Welcome to the Afsharid Color Sorting Project!')
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
end
