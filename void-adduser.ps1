# powershell script to add a new user to the admin and remote desktop group
# display ascii as banner
Write-Host @"

██╗   ██╗ ██████╗ ██╗██████╗ 
██║   ██║██╔═══██╗██║██╔══██╗
██║   ██║██║   ██║██║██║  ██║
╚██╗ ██╔╝██║   ██║██║██║  ██║
 ╚████╔╝ ╚██████╔╝██║██████╔╝
  ╚═══╝   ╚═════╝ ╚═╝╚═════╝ 
                          by @shanksfigarland            
"@


# Define the new user's details
$Username = "shanks"
$Password = ConvertTo-SecureString "Password123!!!!" -AsPlainText -Force

# Create a new user
New-LocalUser -Name $Username -Password $Password -PasswordNeverExpires $true

# Add the new user to the administrators group
Add-LocalGroupMember -Group "Administrators" -Member $Username

# Add the new user to the Remote Desktop Users group
Add-LocalGroupMember -Group "Remote Desktop Users" -Member $Username

Write-Host "User $Username created and added to the Administrators and Remote Desktop Users groups."
