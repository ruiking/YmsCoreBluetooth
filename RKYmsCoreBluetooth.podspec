Pod::Spec.new do |s|
  s.name         = "RKYmsCoreBluetooth"
  s.version      = "0.0.1"
  s.summary      = "[NOT OFFICIAL VERSION] RK YmsCoreBluetooth."

  s.description  = <<-DESC
                    This is a ruiking customized version of YmsCoreBluetooth.
                   DESC

  s.license      = { :type => 'Apache License, Version 2.0', :file => 'LICENSE-2.0.txt' }
  s.homepage     = "http://www.lapsule.com"
  s.author       = { "Jun Du" => "dujun@ruiking.com" }
  s.platform     = :ios, '6.0'
  s.source       = { :git => "https://github.com/ruiking/YmsCoreBluetooth.git", :tag => "0.0.1" }
  s.source_files  = 'YmsCoreBluetooth/*.{h,m,c}' 
  s.exclude_files = 'Deanna*'
  s.requires_arc = true
end
